#include "quip_config.h"

/* morphological image operators */

char VersionId_vec_util_morph[] = QUIP_VERSION_STRING;

#include "data_obj.h"
#include "vec_util.h"
#include "ggem.h"
#include "vecgen.h"
#include "math.h"	/* abs */
#include "debug.h"	/* verbose */

#define PIXTYPE u_char		/* see SeedFill.c BUG */

/* local prototypes */
static float flt_pixelread(long x,long y);
static void flt_pixelwrite(long x,long y,double v);

/* Put a pixel to 0 if ANY of it's neighbors are 1 */

void erode(QSP_ARG_DECL  Data_Obj *dpto,Data_Obj *dpfr)
{
	float *dstp,*srcp;
	u_long i,j;
	long ri;

	if( dpto == dpfr )
		WARN("source and destination should differ for erosion!?");

	if( !is_contiguous(dpfr) ){
		sprintf(error_string,
			"source image %s must be contiguous for erosion",
			dpfr->dt_name);
		WARN(error_string);
		return;
	}
	if( dpto->dt_prec != PREC_SP || dpfr->dt_prec != PREC_SP ){
		WARN("precision must be float for erosion");
		return;
	}
	if( !dp_same_size(QSP_ARG  dpto,dpfr,"erode") ){
		WARN("images must be equal in size for erosion");
		return;
	}

	ri = dpfr->dt_rowinc;

	/* Let's forget about the edges for now... */
	for(i=1;i<(dpto->dt_rows-1);i++){
		dstp=(float *)dpto->dt_data;
		srcp=(float *)dpfr->dt_data;
		dstp += i*dpto->dt_rowinc + dpto->dt_pinc;
		srcp += i*dpfr->dt_rowinc + dpfr->dt_pinc;
		for(j=1;j<(dpto->dt_cols-1);j++){
			if( *srcp     == 1.0 && ( 
			    *(srcp-1) == 0.0 ||
			    *(srcp+1) == 0.0 ||
			    *(srcp-ri) == 0.0 ||
			    *(srcp-ri-1) == 0.0 ||
			    *(srcp-ri+1) == 0.0 ||
			    *(srcp+ri) == 0.0 ||
			    *(srcp+ri-1) == 0.0 ||
			    *(srcp+ri+1) == 0.0 ))
				*dstp = 0.0;
			else {
				if (*srcp == 1.0) *dstp = 1.0;
				else *dstp = 0.0;
			      }
			srcp++;
			dstp+=dpto->dt_pinc;
		}
	}
	/* now do the top row */
	i=0;
		dstp=(float *)dpto->dt_data;
		srcp=(float *)dpfr->dt_data;
		dstp += i*dpto->dt_rowinc + dpto->dt_pinc;
		srcp += i*dpfr->dt_rowinc + dpfr->dt_pinc;
		for(j=1;j<(dpto->dt_cols-1);j++){
			if( *srcp     == 1.0 && (
			    *(srcp-1) == 0.0 ||
			    *(srcp+1) == 0.0 ||
			    /* could wrap around here */
			    *(srcp+ri) == 0.0 ||
			    *(srcp+ri-1) == 0.0 ||
			    *(srcp+ri+1) == 0.0 ))
				*dstp = 0.0;
			else {
				if (*srcp == 1.0) *dstp = 1.0;
			           else *dstp = 0.0;
                              }
			srcp++;
			dstp+=dpto->dt_pinc;
		}
	/* now do the top row */
	i=dpto->dt_rows-1;
		dstp=(float *)dpto->dt_data;
		srcp=(float *)dpfr->dt_data;
		dstp += i*dpto->dt_rowinc + dpto->dt_pinc;
		srcp += i*dpfr->dt_rowinc + dpfr->dt_pinc;
		for(j=1;j<(dpto->dt_cols-1);j++){
			if( *srcp     == 1.0 && (
			    *(srcp-1) == 0.0 ||
			    *(srcp+1) == 0.0 ||
			    *(srcp-ri) == 0.0 ||
			    *(srcp-ri-1) == 0.0 ||
			    *(srcp-ri+1) == 0.0 ))
				*dstp = 0.0;
			else {
			if (*srcp == 1.0) *dstp = 1.0;
			  else *dstp = 0.0;
		             }
			srcp++;
			dstp+=dpto->dt_pinc;
		}
	/* now do the left column */
	j=0;
	for(i=1;i<(dpto->dt_rows-1);i++){
		dstp=(float *)dpto->dt_data;
		srcp=(float *)dpfr->dt_data;
		dstp += i*dpto->dt_rowinc + j * dpto->dt_pinc;
		srcp += i*dpfr->dt_rowinc + j * dpfr->dt_pinc;
		if( *srcp     == 1.0 && (
		    *(srcp+1) == 0.0 ||
		    *(srcp-ri) == 0.0 ||
		    *(srcp-ri+1) == 0.0 ||
		    *(srcp+ri) == 0.0 ||
		    *(srcp+ri+1) == 0.0 ))
			*dstp = 0.0;
		else {
		if (*srcp == 1.0) *dstp = 1.0;
		 else *dstp = 0.0;
		     }
	}
	/* now do the right column */
	j=dpto->dt_cols-1;
	for(i=1;i<(dpto->dt_rows-1);i++){
		dstp=(float *)dpto->dt_data;
		srcp=(float *)dpfr->dt_data;
		dstp += i*dpto->dt_rowinc + j * dpto->dt_pinc ;
		srcp += i*dpfr->dt_rowinc + j * dpfr->dt_pinc ;
		if( *srcp     == 1.0 && (
		    *(srcp-1) == 0.0 ||
		    *(srcp-ri) == 0.0 ||
		    *(srcp-ri-1) == 0.0 ||
		    *(srcp+ri) == 0.0 ||
		    *(srcp+ri-1) == 0.0 ))
			*dstp = 0.0;
		else {
		if (*srcp == 1.0) *dstp = 1.0;
		  else *dstp = 0.0;
		     }
	}
	/* do we care about the corners??? */
	/* upper left */
	i=0;
	j=0;
	dstp=(float *)dpto->dt_data;
	srcp=(float *)dpfr->dt_data;
	dstp += i*dpto->dt_rowinc + j * dpto->dt_pinc ;
	srcp += i*dpfr->dt_rowinc + j * dpfr->dt_pinc ;
	if( *srcp     == 1.0 && (
	    *(srcp+1) == 0.0 ||
	    *(srcp+ri) == 0.0 ||
	    *(srcp+ri+1) == 0.0 ))
		*dstp = 0.0;
	else {
		if (*srcp == 1.0) *dstp = 1.0;
	         else *dstp = 0.0;
	     }
	/* lower left */
	j=0;
	i=dpto->dt_rows-1;
	dstp=(float *)dpto->dt_data;
	srcp=(float *)dpfr->dt_data;
	dstp += i*dpto->dt_rowinc + j * dpto->dt_pinc ;
	srcp += i*dpfr->dt_rowinc + j * dpfr->dt_pinc ;
	if( *srcp     == 1.0 && (
	    *(srcp+1) == 0.0 ||
	    *(srcp-ri) == 0.0 ||
	    *(srcp+1-ri) == 0.0 ))
		*dstp = 0.0;
	else	{
		if (*srcp == 1.0) *dstp = 1.0;
	           else *dstp = 0.0;
		}
	/* upper right */
	j=dpto->dt_cols-1;
	i=0;
	dstp=(float *)dpto->dt_data;
	srcp=(float *)dpfr->dt_data;
	dstp += i*dpto->dt_rowinc + j * dpto->dt_pinc ;
	srcp += i*dpfr->dt_rowinc + j * dpfr->dt_pinc ;
	if( *srcp     == 1.0 && (
	    *(srcp-1) == 0.0 ||
	    *(srcp+ri) == 0.0 ||
	    *(srcp+ri-1) == 0.0 ))
		*dstp = 0.0;
	else	{
		if (*srcp == 1.0) *dstp = 1.0;
	  	else *dstp = 0.0;
		}
	/* lower right */
	i=dpto->dt_rows-1;
	j=dpto->dt_cols-1;
	dstp=(float *)dpto->dt_data;
	srcp=(float *)dpfr->dt_data;
	dstp += i*dpto->dt_rowinc + j * dpto->dt_pinc ;
	srcp += i*dpfr->dt_rowinc + j * dpfr->dt_pinc ;
	if( *srcp     == 1.0 && (
	    *(srcp-1) == 0.0 ||
	    *(srcp-ri) == 0.0 ||
	    *(srcp-ri-1) == 0.0 ))
		*dstp = 0.0;
	else{
		if (*srcp == 1.0) *dstp = 1.0;
	        else *dstp = 0.0;
	      }
}



/* set a pixel to 0 if ANY of it's neighbors are 0 */

void dilate(QSP_ARG_DECL  Data_Obj *dpto,Data_Obj *dpfr)
{
	float *dstp,*srcp;
	u_long i,j;
	long ri;

	if( dpto == dpfr )
		WARN("source and destination should differ for dilation!?");

	if( !is_contiguous(dpfr) ){
		sprintf(error_string,
			"source image %s must be contiguous for dilation",
			dpfr->dt_name);
		WARN(error_string);
		return;
	}
	if( dpto->dt_prec != PREC_SP || dpfr->dt_prec != PREC_SP ){
		WARN("precision must be float for dilation");
		return;
	}
	if( !dp_same_size(QSP_ARG  dpto,dpfr,"dilate") ){
		WARN("images must be equal in size for dilation");
		return;
	}

	ri = dpfr->dt_rowinc;

	/* Let's forget about the edges for now... */
	for(i=1;i<(dpto->dt_rows-1);i++){
		dstp=(float *)dpto->dt_data;
		srcp=(float *)dpfr->dt_data;
		dstp += i*dpto->dt_rowinc + dpto->dt_pinc;
		srcp += i*dpfr->dt_rowinc + dpfr->dt_pinc;
		for(j=1;j<(dpto->dt_cols-1);j++){
			if( *srcp     == 1.0 ||
			    *(srcp-1) == 1.0 ||
			    *(srcp+1) == 1.0 ||
			    *(srcp-ri) == 1.0 ||
			    *(srcp-ri-1) == 1.0 ||
			    *(srcp-ri+1) == 1.0 ||
			    *(srcp+ri) == 1.0 ||
			    *(srcp+ri-1) == 1.0 ||
			    *(srcp+ri+1) == 1.0 )
				*dstp = 1.0;
			else
				*dstp = 0.0;
			srcp++;
			dstp+=dpto->dt_pinc;
		}
	}
	/* now do the top row */
	i=0;
		dstp=(float *)dpto->dt_data;
		srcp=(float *)dpfr->dt_data;
		dstp += i*dpto->dt_rowinc + dpto->dt_pinc;
		srcp += i*dpfr->dt_rowinc + dpfr->dt_pinc;
		for(j=1;j<(dpto->dt_cols-1);j++){
			if( *srcp     == 1.0 ||
			    *(srcp-1) == 1.0 ||
			    *(srcp+1) == 1.0 ||
			    /* could wrap around here */
			    *(srcp+ri) == 1.0 ||
			    *(srcp+ri-1) == 1.0 ||
			    *(srcp+ri+1) == 1.0 )
				*dstp = 1.0;
			else
				*dstp = 0.0;
			srcp++;
			dstp+=dpto->dt_pinc;
		}
	/* now do the top row */
	i=dpto->dt_rows-1;
		dstp=(float *)dpto->dt_data;
		srcp=(float *)dpfr->dt_data;
		dstp += i*dpto->dt_rowinc + dpto->dt_pinc;
		srcp += i*dpfr->dt_rowinc + dpfr->dt_pinc;
		for(j=1;j<(dpto->dt_cols-1);j++){
			if( *srcp     == 1.0 ||
			    *(srcp-1) == 1.0 ||
			    *(srcp+1) == 1.0 ||
			    *(srcp-ri) == 1.0 ||
			    *(srcp-ri-1) == 1.0 ||
			    *(srcp-ri+1) == 1.0 )
				*dstp = 1.0;
			else
				*dstp = 0.0;
			srcp++;
			dstp+=dpto->dt_pinc;
		}
	/* now do the left column */
	j=0;
	for(i=1;i<(dpto->dt_rows-1);i++){
		dstp=(float *)dpto->dt_data;
		srcp=(float *)dpfr->dt_data;
		dstp += i*dpto->dt_rowinc + j * dpto->dt_pinc;
		srcp += i*dpfr->dt_rowinc + j * dpfr->dt_pinc;
		if( *srcp     == 1.0 ||
		    *(srcp+1) == 1.0 ||
		    *(srcp-ri) == 1.0 ||
		    *(srcp-ri+1) == 1.0 ||
		    *(srcp+ri) == 1.0 ||
		    *(srcp+ri+1) == 1.0 )
			*dstp = 1.0;
		else
			*dstp = 0.0;
	}
	/* now do the right column */
	j=dpto->dt_cols-1;
	for(i=1;i<(dpto->dt_rows-1);i++){
		dstp=(float *)dpto->dt_data;
		srcp=(float *)dpfr->dt_data;
		dstp += i*dpto->dt_rowinc + j * dpto->dt_pinc ;
		srcp += i*dpfr->dt_rowinc + j * dpfr->dt_pinc ;
		if( *srcp     == 1.0 ||
		    *(srcp-1) == 1.0 ||
		    *(srcp-ri) == 1.0 ||
		    *(srcp-ri-1) == 1.0 ||
		    *(srcp+ri) == 1.0 ||
		    *(srcp+ri-1) == 1.0 )
			*dstp = 1.0;
		else
			*dstp = 0.0;
	}
	/* do we care about the corners??? */
	/* upper left */
	i=0;
	j=0;
	dstp=(float *)dpto->dt_data;
	srcp=(float *)dpfr->dt_data;
	dstp += i*dpto->dt_rowinc + j * dpto->dt_pinc ;
	srcp += i*dpfr->dt_rowinc + j * dpfr->dt_pinc ;
	if( *srcp     == 1.0 ||
	    *(srcp+1) == 1.0 ||
	    *(srcp+ri) == 1.0 ||
	    *(srcp+ri+1) == 1.0 )
		*dstp = 1.0;
	else
		*dstp = 0.0;
	/* lower left */
	j=0;
	i=dpto->dt_rows-1;
	dstp=(float *)dpto->dt_data;
	srcp=(float *)dpfr->dt_data;
	dstp += i*dpto->dt_rowinc + j * dpto->dt_pinc ;
	srcp += i*dpfr->dt_rowinc + j * dpfr->dt_pinc ;
	if( *srcp     == 1.0 ||
	    *(srcp+1) == 1.0 ||
	    *(srcp-ri) == 1.0 ||
	    *(srcp+1-ri) == 1.0 )
		*dstp = 1.0;
	else
		*dstp = 0.0;
	/* upper right */
	j=dpto->dt_cols-1;
	i=0;
	dstp=(float *)dpto->dt_data;
	srcp=(float *)dpfr->dt_data;
	dstp += i*dpto->dt_rowinc + j * dpto->dt_pinc ;
	srcp += i*dpfr->dt_rowinc + j * dpfr->dt_pinc ;
	if( *srcp     == 1.0 ||
	    *(srcp-1) == 1.0 ||
	    *(srcp+ri) == 1.0 ||
	    *(srcp+ri-1) == 1.0 )
		*dstp = 1.0;
	else
		*dstp = 0.0;
	/* lower right */
	i=dpto->dt_rows-1;
	j=dpto->dt_cols-1;
	dstp=(float *)dpto->dt_data;
	srcp=(float *)dpfr->dt_data;
	dstp += i*dpto->dt_rowinc + j * dpto->dt_pinc ;
	srcp += i*dpfr->dt_rowinc + j * dpfr->dt_pinc ;
	if( *srcp     == 1.0 ||
	    *(srcp-1) == 1.0 ||
	    *(srcp-ri) == 1.0 ||
	    *(srcp-ri-1) == 1.0 )
		*dstp = 1.0;
	else
		*dstp = 0.0;
}


/* flood fill stuff using graphics gems routine */

static Data_Obj *fill_dp=NO_OBJ;

int pixelread(int x,int y)
{
	return( (int) *( ((PIXTYPE *)fill_dp->dt_data)
		+ x * fill_dp->dt_pinc
		+ y * fill_dp->dt_rinc ) );
}

void pixelwrite(int x,int y,int v)
{
	*( ((PIXTYPE *)fill_dp->dt_data)
		+ x * fill_dp->dt_pinc
		+ y * fill_dp->dt_rinc ) = v;
}

static float flt_pixelread(long x,long y)
{
	return( *( ((float *)fill_dp->dt_data)
		+ x * fill_dp->dt_pinc
		+ y * fill_dp->dt_rinc ) );
}

static void flt_pixelwrite(long x,long y,double v)
{
	*( ((float *)fill_dp->dt_data)
		+ x * fill_dp->dt_pinc
		+ y * fill_dp->dt_rinc ) = v;
}

static float flt_ov;	/* original value at seed pt */
static float flt_nv;
static float flt_tol;

static int flt_inside(long x, long y)
{
	float v;

	v=flt_pixelread(x,y);
	if( verbose ){
		sprintf(msg_str,"value at %ld %ld is %g, orig_val = %g, tol = %g",
			x,y,v,flt_ov,flt_tol);
		prt_msg(msg_str);
	}
	if( fabs(v - flt_ov) <= flt_tol ){
		if( verbose ){
			sprintf(msg_str,"pixel at %ld %ld is inside fill region",x,y);
			prt_msg(msg_str);
		}
		return(1);
	} else {
		if( verbose ){
			sprintf(msg_str,"pixel at %ld %ld is NOT inside fill region",x,y);
			prt_msg(msg_str);
		}
		return(0);
	}
}

static void flt_fill(long x, long y)
{
	if( verbose ){
		sprintf(msg_str,"Filling pixel at %ld %ld with value %g",
			x,y,flt_nv);
		prt_msg(msg_str);
	}
	flt_pixelwrite(x,y,flt_nv);
}

/* Uses the graphics gems fill only for byte images?
 */

void ifl(QSP_ARG_DECL  Data_Obj *dp,dimension_t x,dimension_t y,double color,double tol)
{

#ifdef CAUTIOUS
	if( dp == NO_OBJ ){
		WARN("CAUTIOUS:  ifl:  null fill object passed");
		return;
	}
#endif /* CAUTIOUS */

	fill_dp = dp;
	if( dp->dt_prec == PREC_UBY ){
/*
sprintf(error_string,"ifl( %s, %ld, %ld, color = %g, tol = %g )",dp->dt_name,x,y,color,tol);
advise(error_string);
*/
		ggem_fill(QSP_ARG  (int)x,(int)y,(int)dp->dt_cols,(int)dp->dt_rows,(PIXTYPE)color,(int)tol);
		return;
	} else if( dp->dt_prec == PREC_SP ){
		flt_ov = flt_pixelread(x,y);
		flt_nv = color;
		flt_tol = tol;

		/* check that the inside rule fails for the new color */
		if( fabs(flt_nv-flt_ov) <= flt_tol ){
			sprintf(error_string,
"fill value (%g) too close to seed point value (%g) (tolerance = %g)",
				flt_nv,flt_ov,flt_tol);
			WARN(error_string);
			return;
		}
		gen_fill(x,y,dp,flt_inside,flt_fill);
	} else {
		sprintf(error_string,"ifl:  Sorry, precision %s (object %s) is not supported",
			prec_name[MACHINE_PREC(dp)],dp->dt_name);
		WARN(error_string);
		sprintf(error_string,"Supported precisions for ifl() are %s and %s",
			prec_name[PREC_UBY],prec_name[PREC_SP]);
		advise(error_string);
	}
}


/* Here we define a general binary image processing function that determines each
 * output bit based on the values in a 3x3 neighborhood.   The 9 pixel values are used
 * to construct a 9 bit index word, then the output bit is read from a table.
 * This provides a flexible scheme under which we can implement erode and dilate as
 * well as other useful functions.
 *
 * We borrow some efficiency ideas from median.c  ...
 */

#define SET_OUTPUT						\
								\
	{							\
								\
	index =     b0						\
		| ( b1 ? 2 : 0 )				\
		| ( b2 ? 4 : 0 )				\
		| ( b3 ? 8 : 0 )				\
		| ( b4 ? 16 : 0 )				\
		| ( b5 ? 32 : 0 )				\
		| ( b6 ? 64 : 0 )				\
		| ( b7 ? 128 : 0 )				\
		| ( b8 ? 256 : 0 )				\
		;						\
								\
	if( table[index] )					\
		*to |= outbit;					\
	else							\
		*to &= ~outbit;					\
								\
	ADVANCE_BIT(outbit,to);					\
								\
	}

#define ROTATE_INPUTS						\
								\
	b0 = b1; b1 = b2;					\
	b3 = b4; b4 = b5;					\
	b6 = b7; b7 = b8;

#define ADVANCE_BIT(bit,addr)					\
								\
	if( bit == 0x80000000 ){				\
		bit = 1;					\
		addr ++;					\
	} else {						\
		bit <<= 1;					\
	}

void morph_process( QSP_ARG_DECL  Data_Obj *dpto, Data_Obj *dpfr, Data_Obj *tbl_dp )
{
	dimension_t i,j;
	u_long *to, *from1, *from2, *from3;
	int bitfr1,bitfr2,bitfr3;
	u_long outbit,bit1,bit2,bit3;
	int b0,b1,b2,b3,b4,b5,b6,b7,b8;
	int index;
	u_char *table;

	if( tbl_dp->dt_cols != 512 ){
		sprintf(error_string,"Table vector %s (%d) should have 512 columns",
			tbl_dp->dt_name,tbl_dp->dt_cols);
		WARN(error_string);
		return;
	}
	if( MACHINE_PREC(tbl_dp) != PREC_UBY ){
		sprintf(error_string,"Table vector %s (%s) should have %s precision",
			tbl_dp->dt_name,name_for_prec(tbl_dp->dt_prec),
			name_for_prec(PREC_UBY));
		WARN(error_string);
		return;
	}
	table=(u_char *)tbl_dp->dt_data;
	if( dpto == dpfr ){
		WARN("target and source must be distinct for morphological filter");
		return;
		/* BUG this will not catch subobjects that share data, so be careful! */
	}
	if( dpto->dt_prec != PREC_BIT ){
		sprintf(error_string,"target image %s (%s) must have %s precision",
			dpto->dt_name,name_for_prec(dpto->dt_prec),name_for_prec(PREC_BIT));
		WARN(error_string);
		return;
	}
	if( dpfr->dt_prec != PREC_BIT ){
		sprintf(error_string,"source image %s (%s) must have %s precision",
			dpfr->dt_name,name_for_prec(dpfr->dt_prec),name_for_prec(PREC_BIT));
		WARN(error_string);
		return;
	}
	if( !IS_CONTIGUOUS(dpto) || !IS_CONTIGUOUS(dpfr) ){
		sprintf(error_string,
			"%s and %s must be contiguous for morphological filter",
			dpto->dt_name,dpfr->dt_name);
		WARN(error_string);
		return;
	}


	/* We want to remember what we already know as we move across the image...
	 *
	 * What should we do about the edges?
	 * We might assume all 0's, or extend the edge values off the image...
	 */

	to = (u_long *)dpto->dt_data;
	outbit = 1 << dpto->dt_bit0;

	from1 = from2 = from3 = (u_long *)dpfr->dt_data;
	bitfr2 = bitfr1 = dpfr->dt_bit0;

	from3 += (dpfr->dt_cols/32);
	bitfr3 = dpfr->dt_bit0 + (dpfr->dt_cols%32);
	if( bitfr3 >= 32 ){
		bitfr3 -= 32;
		from3++;
	}

	bit1 = 1 << bitfr1;
	bit2 = 1 << bitfr2;
	bit3 = 1 << bitfr3;

	/*		0 1 2
	 *		3 4 5
	 *		6 7 8
	 */

	b0=b1=b2=b3=b6=0;	/* default values for upper left hand corner */
	i=0;
	/* Do the upper left hand corner */
	b0 = b1 = b3 = b4 = (*from2) & bit2 ? 1 : 0;
	ADVANCE_BIT(bit2,from2)
	b2 = b5 = (*from2) & bit2 ? 1 : 0;
	ADVANCE_BIT(bit2,from2)

	b6 = b7 = (*from3) & bit3 ? 1 : 0;
	ADVANCE_BIT(bit3,from3)
	b8 = (*from3) & bit3 ? 1 : 0;
	ADVANCE_BIT(bit3,from3)

	SET_OUTPUT

	/* Do the first row.
	 *
	 * We advance b5, b8, then copy the first row...
	 */

	for(j=1;j<(dpto->dt_cols-1);j++){
		ROTATE_INPUTS
		b5 = (*from2) & bit2 ? 1 : 0;
		ADVANCE_BIT(bit2,from2)
		b2=b5;
		b8 = (*from3) & bit3 ? 1 : 0;
		ADVANCE_BIT(bit3,from3)

		SET_OUTPUT
	}
		
	/* Do the upper right hand corner */
	ROTATE_INPUTS
	/* copy over the right-hand column */
	b2 = b1;
	b5 = b4;
	b8 = b7;

	SET_OUTPUT

	/* Now from2, from3 should be pointing at the right rows... */

	/* Do the middle rows */
	for(i=1;i<(dpto->dt_rows-1);i++){
		j=0;
		/* Do the left column */
		b1 = (*from1) & bit1 ? 1 : 0;
		ADVANCE_BIT(bit1,from1)
		b4 = (*from2) & bit2 ? 1 : 0;
		ADVANCE_BIT(bit2,from2)
		b7 = (*from3) & bit3 ? 1 : 0;
		ADVANCE_BIT(bit3,from3)
		b0 = b1;
		b3 = b4;
		b6 = b7;
		b2 = (*from1) & bit1 ? 1 : 0;
		ADVANCE_BIT(bit1,from1)
		b5 = (*from2) & bit2 ? 1 : 0;
		ADVANCE_BIT(bit2,from2)
		b8 = (*from3) & bit3 ? 1 : 0;
		ADVANCE_BIT(bit3,from3)

		SET_OUTPUT

		/* Do the middle columns */

		for(j=1;j<(dpto->dt_cols-1);j++){

			ROTATE_INPUTS

			/* Get a new column */
			b2 = (*from1) & bit1 ? 1 : 0;
			ADVANCE_BIT(bit1,from1)
			b5 = (*from2) & bit2 ? 1 : 0;
			ADVANCE_BIT(bit2,from2)
			b8 = (*from3) & bit3 ? 1 : 0;
			ADVANCE_BIT(bit3,from3)

			SET_OUTPUT

		}
		/* Do the right column */
		ROTATE_INPUTS
		b2 = b1;
		b5 = b4;
		b8 = b7;

		SET_OUTPUT
	}
	/* Do the last row */
	/* Do the lower left hand corner */
	b0 = b1 = (*from1) & bit1 ? 1 : 0;
	ADVANCE_BIT(bit1,from1)
	b2 = (*from1) & bit1 ? 1 : 0;
	ADVANCE_BIT(bit1,from1)

	b3 = b4 = b6 = b7 = (*from2) & bit2 ? 1 : 0;
	ADVANCE_BIT(bit2,from2)
	b5 = b8 = (*from2) & bit2 ? 1 : 0;
	ADVANCE_BIT(bit2,from2)

	SET_OUTPUT
	/* Do the middle of the last row */

	for(j=1;j<(dpto->dt_cols-1);j++){
		ROTATE_INPUTS

		b2 = (*from1) & bit1 ? 1 : 0;
		ADVANCE_BIT(bit1,from1)
		b5 = (*from2) & bit2 ? 1 : 0;
		ADVANCE_BIT(bit2,from2)
		b8=b5;

		SET_OUTPUT
	}
	/* Do the lower right hand corner */
	ROTATE_INPUTS
	b2=b1;
	b5=b4;
	b8=b7;
	SET_OUTPUT
	/* BUG need to set the ASSIGNED flag on the output object here... */
}

