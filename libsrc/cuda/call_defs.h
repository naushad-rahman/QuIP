
/* BUG need to write a special case for rvmov to use 32-bit wide moves */
#define TWO_VEC_MOV_METHOD( name , stat )	TWO_VEC_METHOD(name,stat)


#define TWO_VEC_SCALAR_METHOD( name , stat )	_KC_2V_SCAL( name, type_code, stat )
#define THREE_VEC_METHOD( name , stat )		_KC_3V( name, type_code, stat )
#define TWO_VEC_METHOD( name , stat )		_KC_2V( name, type_code, stat)
#define ONE_VEC_SCALAR_METHOD( name , stat )	_KC_1V_SCAL( name, type_code, stat)
#define BITMAP_DST_TWO_VEC_METHOD( name , op )	_KC_VVMAP( name, type_code , op )
#define BITMAP_DST_ONE_VEC_SCALAR_METHOD( name , op ) 					\
						_KC_VSMAP( name, type_code , op )
#define FIVE_VEC_METHOD( name, stat )		_KC_5V( name, type_code, stat)
#define FOUR_VEC_SCALAR_METHOD( name, stat )	_KC_4V_SCAL( name, type_code, stat)
#define THREE_VEC_2SCALAR_METHOD( name, stat )	_KC_3V_2SCAL( name, type_code, stat)
#define TWO_VEC_3SCALAR_METHOD( name, stat )	_KC_2V_3SCAL( name, type_code, stat)
#define VV_SELECTION_METHOD( name , stat )	_KC_VVSLCT( name, type_code, stat)
#define VS_SELECTION_METHOD( name , stat )	_KC_VSSLCT( name, type_code, stat)
#define SS_SELECTION_METHOD( name , stat )	_KC_SSSLCT( name, type_code, stat)
#define BITMAP_DST_ONE_VEC_METHOD( name, stat ) _KC_DBM_1V( name, type_code, stat)
#define BITMAP_SRC_CONVERSION_METHOD( name, stat ) \
						_KC_SBM_1( name, type_code, stat)
#define TWO_MIXED_RC_VEC_METHOD(name,stat)	_KC_2V_MIXED( name, type_code, stat)
#define TWO_CPX_VEC_METHOD( name,stat )		_KC_CPX_2V( name, type_code, stat)
#define TWO_CPXT_VEC_METHOD( name,stat )	_KC_CPXT_2V( name, type_code, stat)
#define TWO_CPXT_VEC_SCALAR_METHOD( name,stat )	_KC_CPXT_1S_2V( name, type_code, stat)
#define TWO_CPXD_VEC_SCALAR_METHOD( name,stat )	_KC_CPXD_1S_2V( name, type_code, stat)
#define THREE_CPXT_VEC_METHOD( name,stat )	_KC_CPXT_3V( name, type_code, stat)
#define THREE_CPXD_VEC_METHOD( name,stat )	_KC_CPXD_3V( name, type_code, stat)
#define THREE_CPX_VEC_METHOD( name,stat )	_KC_CPX_3V( name, type_code, stat)
#define THREE_MIXED_VEC_METHOD( name , stat )	_KC_CCR_3V( name, type_code, stat)
#define TWO_MIXED_CR_VEC_SCALAR_METHOD(name,stat)	\
						_KC_CR_1S_2V( name, type_code, stat)
#define TWO_CPX_VEC_SCALAR_METHOD( name,stat)	_KC_CPX_1S_2V( name, type_code, stat)
#define ONE_CPX_VEC_SCALAR_METHOD( name,stat)	_KC_CPX_1S_1V( name, type_code, stat)
#define CPX_VV_SELECTION_METHOD( name,stat )	_KC_SBM_CPX_3V( name, type_code, stat)
#define CPX_VS_SELECTION_METHOD( name,stat )	_KC_SBM_CPX_1S_2V(name,type_code,stat)
#define CPX_SS_SELECTION_METHOD( name,stat )	_KC_SBM_CPX_2S_1V(name,type_code,stat)


// These are done differently but appear in veclib/all_vec.c and must be skipped.
#define EXTREMA_LOCATIONS_METHOD( name, augment_test , reset_test , action )
#define RAMP2D_METHOD( name )
#define ONE_VEC_2SCALAR_METHOD( name , stat )
#define PROJECTION_METHOD_2( name , stat1 , stat2 )
#define PROJECTION_METHOD_IDX_2( name , init , stat )
#define PROJECTION_METHOD_3( name, init, stat )
#define ONE_VEC_METHOD(name,stat)
#define CPX_PROJECTION_METHOD_2( name,stat1,stat2)
#define CPX_PROJECTION_METHOD_3(name,stat1,stat2)


#define KERN_CALL_5V( name, statement)		_KC_5V( name, type_code, statement)
#define KERN_CALL_4V_SCAL( name, statement)	_KC_4V_SCAL( name, type_code, statement)
#define KERN_CALL_3V_2SCAL( name, statement)	_KC_3V_2SCAL( name, type_code, statement)
#define KERN_CALL_2V_3SCAL( name, statement)	_KC_2V_3SCAL( name, type_code, statement)
#define KERN_CALL_3V( name, statement)		_KC_3V( name, type_code, statement)
#define KERN_CALL_CPX_3V( name, statement)	_KC_CPX_3V( name, type_code, statement)
#define KERN_CALL_CCR_3V( name, statement)	_KC_CCR_3V( name, type_code, statement)
#define KERN_CALL_CR_1S_2V( name, statement)	_KC_CR_1S_2V( name, type_code, statement)
#define KERN_CALL_CPX_2V( name, statement)	_KC_CPX_2V( name, type_code, statement)
#define KERN_CALL_CPXT_2V( name, statement)	_KC_CPXT_2V( name, type_code, statement)
#define KERN_CALL_CPXT_3V( name, statement)	_KC_CPXT_3V( name, type_code, statement)
#define KERN_CALL_CPXD_3V( name, statement)	_KC_CPXD_3V( name, type_code, statement)
#define KERN_CALL_CPX_1S_2V( name, statement)	_KC_CPX_1S_2V( name, type_code, statement)
#define KERN_CALL_CPXT_1S_2V( name, statement)	_KC_CPXT_1S_2V( name, type_code, statement)
#define KERN_CALL_CPXD_1S_2V( name, statement)	_KC_CPXD_1S_2V( name, type_code, statement)
#define KERN_CALL_CPX_1S_1V( name, statement)	_KC_CPX_1S_1V( name, type_code, statement)
#define KERN_CALL_2V( name, statement)		_KC_2V( name, type_code, statement)
#define KERN_CALL_2V_MIXED( name, statement)	_KC_2V_MIXED( name, type_code, statement)
#define KERN_CALL_1V_SCAL( name, statement)	_KC_1V_SCAL( name, type_code, statement)
#define KERN_CALL_DBM_1V( name, statement)	_KC_DBM_1V( name, type_code, statement)
#define KERN_CALL_DBM_1S( name, statement)	_KC_DBM_1S( name, type_code, statement)
#define KERN_CALL_1V_2SCAL( name, statement)	_KC_1V_2SCAL( name, type_code, statement)
#define KERN_CALL_1V_3SCAL( name, statement)	_KC_1V_3SCAL( name, type_code, statement)
#define KERN_CALL_2V_SCAL( name, statement)	_KC_2V_SCAL( name, type_code, statement)
#define KERN_CALL_MM( name, statement)		_KC_MM( name, type_code, statement)
#define KERN_CALL_MM_IND( name, stat1, stat2)	_KC_MM_IND( name, type_code, stat1, stat2)
#define KERN_CALL_MM_NOCC( name, test1, test2)	_KC_MM_NOCC( name, type_code, test1, test2)
#define KERN_CALL_2V_PROJ(name,expr)		_KC_2V_PROJ( name, type_code, expr)
#define KERN_CALL_3V_PROJ(name)			_KC_3V_PROJ( name, type_code)
#define KERN_CALL_VV_LS( name,d,a,b)		_KC_VV_LS( name, type_code,d,a,b)
#define KERN_CALL_VS_LS( name,d,a,b)		_KC_VS_LS( name, type_code,d,a,b)
#define KERN_CALL_VVSLCT( name, statement )	_KC_VVSLCT( name, type_code, statement )
#define KERN_CALL_VSSLCT( name, statement )	_KC_VSSLCT( name, type_code, statement )
#define KERN_CALL_SSSLCT( name, statement )	_KC_SSSLCT( name, type_code, statement )
#define KERN_CALL_SBM_1( name, statement )	_KC_SBM_1( name, type_code, statement )
#define KERN_CALL_SBM_CPX_3V( name, statement )	_KC_SBM_CPX_3V( name, type_code, statement )
#define KERN_CALL_SBM_CPX_1S_2V( name, statement )	_KC_SBM_CPX_1S_2V( name, type_code, statement )
#define KERN_CALL_SBM_CPX_2S_1V( name, statement )	_KC_SBM_CPX_2S_1V( name, type_code, statement )
#define KERN_CALL_VVMAP( name , op )		_KC_VVMAP( name, type_code , op )
#define KERN_CALL_VSMAP( name , op )		_KC_VSMAP( name, type_code , op )

#define _KC_5V( n , c , s )			_KERN_CALL_5V( n , c , s )
#define _KC_4V_SCAL( n , c , s )		_KERN_CALL_4V_SCAL( n , c , s )
#define _KC_3V_2SCAL( n , c , s )		_KERN_CALL_3V_2SCAL( n , c , s )
#define _KC_2V_3SCAL( n , c , s )		_KERN_CALL_2V_3SCAL( n , c , s )
#define _KC_3V( n , c , s )			_KERN_CALL_3V( n , c , s )
#define _KC_CPX_3V( n , c , s )			_KERN_CALL_CPX_3V( n , c , s )
#define _KC_CCR_3V( n , c , s )			_KERN_CALL_CCR_3V( n , c , s )
#define _KC_CR_1S_2V( n , c , s )		_KERN_CALL_CR_1S_2V( n , c , s )
#define _KC_CPX_2V( n , c , s )			_KERN_CALL_CPX_2V( n , c , s )
#define _KC_CPXT_2V( n , c , s )		_KERN_CALL_CPXT_2V( n , c , s )
#define _KC_CPXT_3V( n , c , s )		_KERN_CALL_CPXT_3V( n , c , s )
#define _KC_CPXD_3V( n , c , s )		_KERN_CALL_CPXD_3V( n , c , s )
#define _KC_CPX_1S_2V( n , c , s )		_KERN_CALL_CPX_1S_2V( n , c , s )
#define _KC_CPXT_1S_2V( n , c , s )		_KERN_CALL_CPXT_1S_2V( n , c , s )
#define _KC_CPXD_1S_2V( n , c , s )		_KERN_CALL_CPXD_1S_2V( n , c , s )
#define _KC_CPX_1S_1V( n , c , s )		_KERN_CALL_CPX_1S_1V( n , c , s )
#define _KC_2V( n , c , s )			_KERN_CALL_2V( n , c , s )
#define _KC_2V_MIXED( n , c , s )		_KERN_CALL_2V_MIXED( n , c , s )
#define _KC_2V_PROJ( n , c , e )		_KERN_CALL_2V_PROJ( n , c , e )
#define _KC_3V_PROJ( n , c )			_KERN_CALL_3V_PROJ( n , c )
#define _KC_1V_SCAL( n , c , s )		_KERN_CALL_1V_SCAL( n , c , s )
#define _KC_DBM_1S( n , c , s )			_KERN_CALL_DBM_1S( n , c , s )
#define _KC_DBM_1V( n , c , s )			_KERN_CALL_DBM_1V( n , c , s )
#define _KC_1V_2SCAL( n , c , s )		_KERN_CALL_1V_2SCAL( n , c , s )
#define _KC_1V_3SCAL( n , c , s )		_KERN_CALL_1V_3SCAL( n , c , s )
#define _KC_2V_SCAL( n , c , s )		_KERN_CALL_2V_SCAL( n , c , s )
#define _KC_MM( n , c , s )			_KERN_CALL_MM( n , c , s )
#define _KC_MM_IND( n , c , s1 , s2 )		_KERN_CALL_MM_IND( n , c , s1 , s2 )
#define _KC_MM_NOCC( n , c , t1 , t2 )		_KERN_CALL_MM_NOCC( n , c , t1 , t2 )
#define _KC_VV_LS( n , c , d , a , b )		_KERN_CALL_VV_LS( n , c , d , a , b )
#define _KC_VS_LS( n , c , d , a , b )		_KERN_CALL_VS_LS( n , c , d , a , b )
#define _KC_VVSLCT( n , c , s )			_KERN_CALL_VVSLCT( n , c , s )
#define _KC_VSSLCT( n , c , s )			_KERN_CALL_VSSLCT( n , c , s )
#define _KC_SSSLCT( n , c , s )			_KERN_CALL_SSSLCT( n , c , s )
#define _KC_SBM_1( n , c , s )			_KERN_CALL_SBM_1( n , c , s )
#define _KC_SBM_CPX_3V( n , c , s )		_KERN_CALL_SBM_CPX_3V( n , c , s )
#define _KC_SBM_CPX_1S_2V( n , c , s )		_KERN_CALL_SBM_CPX_1S_2V( n , c , s )
#define _KC_SBM_CPX_2S_1V( n , c , s )		_KERN_CALL_SBM_CPX_2S_1V( n , c , s )
#define _KC_VVMAP( n , c , op )			_KERN_CALL_VVMAP( n , c , op )
#define _KC_VSMAP( n , c , op )			_KERN_CALL_VSMAP( n , c , op )

