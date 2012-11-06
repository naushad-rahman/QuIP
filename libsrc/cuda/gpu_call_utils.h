/******************** KERN_XXXX_NAME **********************/

#define KERN_FAST_NAME(name,code)	gpu_fast_##code##_##name
#define KERN_EQSP_NAME(name,code)	gpu_eqsp_##code##_##name
#define KERN_SLOW_NAME(name,code)	gpu_slow_##code##_##name
#define KERN_FLEN_NAME(name,code)	gpu_fast_len_##code##_##name
#define KERN_ELEN_NAME(name,code)	gpu_eqsp_len_##code##_##name
#define KERN_SLEN_NAME(name,code)	gpu_slow_len_##code##_##name


/******************* KERN_ARGS ***************************/

/* These are the arguments used in the declarations of the kernel functions */

//#define KERN_ARGS_1S		std_type sval1
#define KERN_ARGS_1S		std_type scalar1_val
#define KERN_ARGS_2S		KERN_ARGS_1S, std_type scalar2_val
#define KERN_ARGS_3S		KERN_ARGS_2S, std_type scalar3_val

#define KERN_ARGS_CPX_1S	std_cpx cscalar1_val
#define KERN_ARGS_CPX_2S	KERN_ARGS_CPX_1S , std_cpx cscalar2_val

#define KERN_FAST_ARGS_1	dest_type* a
#define KERN_FAST_ARGS_2	KERN_FAST_ARGS_1, KERN_FAST_ARGS_SRC1
#define KERN_FAST_ARGS_SRC1	std_type* b
#define KERN_FAST_ARGS_SRC2	std_type* c
#define KERN_FAST_ARGS_SRC3	std_type* d
#define KERN_FAST_ARGS_SRC4	std_type* e
#define KERN_FAST_ARGS_3	KERN_FAST_ARGS_2, KERN_FAST_ARGS_SRC2
#define KERN_FAST_ARGS_4	KERN_FAST_ARGS_3, KERN_FAST_ARGS_SRC3
#define KERN_FAST_ARGS_5	KERN_FAST_ARGS_4, KERN_FAST_ARGS_SRC4

#define KERN_FAST_ARGS_CPX_1	dest_cpx* a
#define KERN_FAST_ARGS_CPX_SRC1	std_cpx* b
#define KERN_FAST_ARGS_CPX_SRC2	std_cpx* c
#define KERN_FAST_ARGS_CPX_SRC3	std_cpx* d
#define KERN_FAST_ARGS_CPX_SRC4	std_cpx* e

#define KERN_FAST_ARGS_CPX_2	KERN_FAST_ARGS_CPX_1, KERN_FAST_ARGS_CPX_SRC1
#define KERN_FAST_ARGS_CPX_3	KERN_FAST_ARGS_CPX_2, KERN_FAST_ARGS_CPX_SRC2
#define KERN_FAST_ARGS_CPX_4	KERN_FAST_ARGS_CPX_3, KERN_FAST_ARGS_CPX_SRC3
#define KERN_FAST_ARGS_CPX_5	KERN_FAST_ARGS_CPX_4, KERN_FAST_ARGS_CPX_SRC4
#define KERN_FAST_ARGS_CCR_3	KERN_FAST_ARGS_CPX_2, KERN_FAST_ARGS_SRC2

#define KERN_FAST_ARGS_CR_1S_2	KERN_FAST_ARGS_CPX_1, KERN_FAST_ARGS_SRC1, KERN_ARGS_1S
#define KERN_FAST_ARGS_CPX_1S_2	KERN_FAST_ARGS_CPX_2, KERN_ARGS_CPX_1S
#define KERN_FAST_ARGS_CPX_1S_1	KERN_FAST_ARGS_CPX_1, KERN_ARGS_CPX_1S
#define KERN_FAST_ARGS_CPX_2S_1	KERN_FAST_ARGS_CPX_1, KERN_ARGS_CPX_2S

#define KERN_FAST_ARGS_1SRC	KERN_FAST_ARGS_SRC1
#define KERN_FAST_ARGS_2SRCS	KERN_FAST_ARGS_SRC1, KERN_FAST_ARGS_SRC2

#define KERN_FAST_ARGS_RC_2	KERN_FAST_ARGS_1, KERN_FAST_ARGS_CPX_SRC1

#define KERN_EQSP_ARGS_1	dest_type* a, int inc1
#define KERN_EQSP_ARGS_SRC1	std_type* b, int inc2
#define KERN_EQSP_ARGS_SRC2	std_type* c, int inc3
#define KERN_EQSP_ARGS_SRC3	std_type* d, int inc4
#define KERN_EQSP_ARGS_SRC4	std_type* e, int inc5
#define KERN_EQSP_ARGS_1SRC	KERN_EQSP_ARGS_SRC1
#define KERN_EQSP_ARGS_2SRCS	KERN_EQSP_ARGS_SRC1, KERN_EQSP_ARGS_SRC2
#define KERN_EQSP_ARGS_2	KERN_EQSP_ARGS_1, KERN_EQSP_ARGS_SRC1
#define KERN_EQSP_ARGS_3	KERN_EQSP_ARGS_2, KERN_EQSP_ARGS_SRC2
#define KERN_EQSP_ARGS_4	KERN_EQSP_ARGS_3, KERN_EQSP_ARGS_SRC3
#define KERN_EQSP_ARGS_5	KERN_EQSP_ARGS_4, KERN_EQSP_ARGS_SRC4

#define KERN_EQSP_ARGS_CPX_1	dest_cpx* a, int inc1
#define KERN_EQSP_ARGS_CPX_SRC1	std_cpx* b, int inc2
#define KERN_EQSP_ARGS_CPX_SRC2	std_cpx* c, int inc3
#define KERN_EQSP_ARGS_CPX_SRC3	std_cpx* d, int inc4
#define KERN_EQSP_ARGS_CPX_SRC4	std_cpx* e, int inc5
#define KERN_EQSP_ARGS_CPX_1SRC	KERN_EQSP_ARGS_CPX_SRC1
#define KERN_EQSP_ARGS_CPX_2SRCS	KERN_EQSP_ARGS_CPX_SRC1, KERN_EQSP_ARGS_CPX_SRC2
#define KERN_EQSP_ARGS_CPX_2	KERN_EQSP_ARGS_CPX_1, KERN_EQSP_ARGS_CPX_SRC1
#define KERN_EQSP_ARGS_CPX_3	KERN_EQSP_ARGS_CPX_2, KERN_EQSP_ARGS_CPX_SRC2
#define KERN_EQSP_ARGS_CPX_4	KERN_EQSP_ARGS_CPX_3, KERN_EQSP_ARGS_CPX_SRC3
#define KERN_EQSP_ARGS_CPX_5	KERN_EQSP_ARGS_CPX_4, KERN_EQSP_ARGS_CPX_SRC4

#define KERN_EQSP_ARGS_CCR_3	KERN_EQSP_ARGS_CPX_2, KERN_EQSP_ARGS_SRC2
#define KERN_EQSP_ARGS_RC_2	KERN_EQSP_ARGS_1, KERN_EQSP_ARGS_CPX_SRC1
#define KERN_EQSP_ARGS_CR_1S_2	KERN_EQSP_ARGS_CPX_1, KERN_EQSP_ARGS_SRC1, KERN_ARGS_1S
#define KERN_EQSP_ARGS_CPX_1S_2	KERN_EQSP_ARGS_CPX_2, KERN_ARGS_CPX_1S
#define KERN_EQSP_ARGS_CPX_1S_1	KERN_EQSP_ARGS_CPX_1, KERN_ARGS_CPX_1S
#define KERN_EQSP_ARGS_CPX_2S_1	KERN_EQSP_ARGS_CPX_1, KERN_ARGS_CPX_2S

#define KERN_SLOW_ARGS_1	dest_type* a, dim3 inc1
#define KERN_SLOW_ARGS_SRC1	std_type* b, dim3 inc2
#define KERN_SLOW_ARGS_SRC2	std_type* c, dim3 inc3
#define KERN_SLOW_ARGS_SRC3	std_type* d, dim3 inc4
#define KERN_SLOW_ARGS_SRC4	std_type* e, dim3 inc5
#define KERN_SLOW_ARGS_2	KERN_SLOW_ARGS_1, KERN_SLOW_ARGS_SRC1
#define KERN_SLOW_ARGS_3	KERN_SLOW_ARGS_2, KERN_SLOW_ARGS_SRC2
#define KERN_SLOW_ARGS_4	KERN_SLOW_ARGS_3, KERN_SLOW_ARGS_SRC3
#define KERN_SLOW_ARGS_5	KERN_SLOW_ARGS_4, KERN_SLOW_ARGS_SRC4

#define KERN_SLOW_ARGS_CPX_1	dest_cpx* a, dim3 inc1
#define KERN_SLOW_ARGS_CPX_SRC1	std_cpx* b, dim3 inc2
#define KERN_SLOW_ARGS_CPX_SRC2	std_cpx* c, dim3 inc3
#define KERN_SLOW_ARGS_CPX_SRC3	std_cpx* d, dim3 inc4
#define KERN_SLOW_ARGS_CPX_SRC4	std_cpx* e, dim3 inc5
#define KERN_SLOW_ARGS_CPX_2	KERN_SLOW_ARGS_CPX_1, KERN_SLOW_ARGS_CPX_SRC1
#define KERN_SLOW_ARGS_CPX_3	KERN_SLOW_ARGS_CPX_2, KERN_SLOW_ARGS_CPX_SRC2
#define KERN_SLOW_ARGS_CPX_4	KERN_SLOW_ARGS_CPX_3, KERN_SLOW_ARGS_CPX_SRC3
#define KERN_SLOW_ARGS_CPX_5	KERN_SLOW_ARGS_CPX_4, KERN_SLOW_ARGS_CPX_SRC4

#define KERN_SLOW_ARGS_1SRC	KERN_SLOW_ARGS_SRC1
#define KERN_SLOW_ARGS_2SRCS	KERN_SLOW_ARGS_SRC1, KERN_SLOW_ARGS_SRC2

#define KERN_SLOW_ARGS_CCR_3	KERN_SLOW_ARGS_CPX_2, KERN_SLOW_ARGS_SRC2
#define KERN_SLOW_ARGS_RC_2	KERN_SLOW_ARGS_1, KERN_SLOW_ARGS_CPX_SRC1
#define KERN_SLOW_ARGS_CR_1S_2	KERN_SLOW_ARGS_CPX_1, KERN_SLOW_ARGS_SRC1, KERN_ARGS_1S
#define KERN_SLOW_ARGS_CPX_1S_2	KERN_SLOW_ARGS_CPX_2, KERN_ARGS_CPX_1S
#define KERN_SLOW_ARGS_CPX_1S_1	KERN_SLOW_ARGS_CPX_1, KERN_ARGS_CPX_1S
#define KERN_SLOW_ARGS_CPX_2S_1	KERN_SLOW_ARGS_CPX_1, KERN_ARGS_CPX_2S

#define KERN_FAST_ARG_LEN	int len
#define KERN_EQSP_ARG_LEN	int len
#define KERN_SLOW_ARG_LEN	dim3 len

#define KERN_FLEN_ARGS_1	KERN_FAST_ARGS_1, KERN_FAST_ARG_LEN
#define KERN_FLEN_ARGS_2	KERN_FAST_ARGS_2, KERN_FAST_ARG_LEN
#define KERN_FLEN_ARGS_3	KERN_FAST_ARGS_3, KERN_FAST_ARG_LEN
#define KERN_FLEN_ARGS_4	KERN_FAST_ARGS_4, KERN_FAST_ARG_LEN
#define KERN_FLEN_ARGS_5	KERN_FAST_ARGS_5, KERN_FAST_ARG_LEN

#define KERN_ELEN_ARGS_1	KERN_EQSP_ARGS_1, KERN_EQSP_ARG_LEN
#define KERN_ELEN_ARGS_2	KERN_EQSP_ARGS_2, KERN_EQSP_ARG_LEN
#define KERN_ELEN_ARGS_3	KERN_EQSP_ARGS_3, KERN_EQSP_ARG_LEN
#define KERN_ELEN_ARGS_4	KERN_EQSP_ARGS_4, KERN_EQSP_ARG_LEN
#define KERN_ELEN_ARGS_5	KERN_EQSP_ARGS_5, KERN_EQSP_ARG_LEN

#define KERN_SLEN_ARGS_1	KERN_SLOW_ARGS_1, KERN_SLOW_ARG_LEN
#define KERN_SLEN_ARGS_2	KERN_SLOW_ARGS_2, KERN_SLOW_ARG_LEN
#define KERN_SLEN_ARGS_3	KERN_SLOW_ARGS_3, KERN_SLOW_ARG_LEN
#define KERN_SLEN_ARGS_4	KERN_SLOW_ARGS_4, KERN_SLOW_ARG_LEN
#define KERN_SLEN_ARGS_5	KERN_SLOW_ARGS_5, KERN_SLOW_ARG_LEN

#define KERN_FLEN_ARGS_CPX_1	KERN_FAST_ARGS_CPX_1, KERN_FAST_ARG_LEN
#define KERN_FLEN_ARGS_CPX_2	KERN_FAST_ARGS_CPX_2, KERN_FAST_ARG_LEN
#define KERN_FLEN_ARGS_CPX_3	KERN_FAST_ARGS_CPX_3, KERN_FAST_ARG_LEN
#define KERN_FLEN_ARGS_CPX_4	KERN_FAST_ARGS_CPX_4, KERN_FAST_ARG_LEN
#define KERN_FLEN_ARGS_CPX_5	KERN_FAST_ARGS_CPX_5, KERN_FAST_ARG_LEN

#define KERN_ELEN_ARGS_CPX_1	KERN_EQSP_ARGS_CPX_1, KERN_EQSP_ARG_LEN
#define KERN_ELEN_ARGS_CPX_2	KERN_EQSP_ARGS_CPX_2, KERN_EQSP_ARG_LEN
#define KERN_ELEN_ARGS_CPX_3	KERN_EQSP_ARGS_CPX_3, KERN_EQSP_ARG_LEN
#define KERN_ELEN_ARGS_CPX_4	KERN_EQSP_ARGS_CPX_4, KERN_EQSP_ARG_LEN
#define KERN_ELEN_ARGS_CPX_5	KERN_EQSP_ARGS_CPX_5, KERN_EQSP_ARG_LEN

#define KERN_SLEN_ARGS_CPX_1	KERN_SLOW_ARGS_CPX_1, KERN_SLOW_ARG_LEN
#define KERN_SLEN_ARGS_CPX_2	KERN_SLOW_ARGS_CPX_2, KERN_SLOW_ARG_LEN
#define KERN_SLEN_ARGS_CPX_3	KERN_SLOW_ARGS_CPX_3, KERN_SLOW_ARG_LEN
#define KERN_SLEN_ARGS_CPX_4	KERN_SLOW_ARGS_CPX_4, KERN_SLOW_ARG_LEN
#define KERN_SLEN_ARGS_CPX_5	KERN_SLOW_ARGS_CPX_5, KERN_SLOW_ARG_LEN

#define KERN_FLEN_ARGS_RC_2	KERN_FAST_ARGS_RC_2, KERN_FAST_ARG_LEN
#define KERN_ELEN_ARGS_RC_2	KERN_EQSP_ARGS_RC_2, KERN_EQSP_ARG_LEN
#define KERN_SLEN_ARGS_RC_2	KERN_SLOW_ARGS_RC_2, KERN_SLOW_ARG_LEN

#define KERN_FLEN_ARGS_CCR_3	KERN_FAST_ARGS_CCR_3, KERN_FAST_ARG_LEN
#define KERN_ELEN_ARGS_CCR_3	KERN_EQSP_ARGS_CCR_3, KERN_EQSP_ARG_LEN
#define KERN_SLEN_ARGS_CCR_3	KERN_SLOW_ARGS_CCR_3, KERN_SLOW_ARG_LEN

#define KERN_FLEN_ARGS_CR_1S_2	KERN_FAST_ARGS_CR_1S_2, KERN_FAST_ARG_LEN
#define KERN_ELEN_ARGS_CR_1S_2	KERN_EQSP_ARGS_CR_1S_2, KERN_EQSP_ARG_LEN
#define KERN_SLEN_ARGS_CR_1S_2	KERN_SLOW_ARGS_CR_1S_2, KERN_SLOW_ARG_LEN

#define KERN_FLEN_ARGS_CPX_1S_2	KERN_FAST_ARGS_CPX_1S_2, KERN_FAST_ARG_LEN
#define KERN_ELEN_ARGS_CPX_1S_2	KERN_EQSP_ARGS_CPX_1S_2, KERN_EQSP_ARG_LEN
#define KERN_SLEN_ARGS_CPX_1S_2	KERN_SLOW_ARGS_CPX_1S_2, KERN_SLOW_ARG_LEN

#define KERN_FLEN_ARGS_CPX_1S_1	KERN_FAST_ARGS_CPX_1S_1, KERN_FAST_ARG_LEN
#define KERN_ELEN_ARGS_CPX_1S_1	KERN_EQSP_ARGS_CPX_1S_1, KERN_EQSP_ARG_LEN
#define KERN_SLEN_ARGS_CPX_1S_1	KERN_SLOW_ARGS_CPX_1S_1, KERN_SLOW_ARG_LEN

#define KERN_FLEN_ARGS_CPX_2S_1	KERN_FAST_ARGS_CPX_2S_1, KERN_FAST_ARG_LEN
#define KERN_ELEN_ARGS_CPX_2S_1	KERN_EQSP_ARGS_CPX_2S_1, KERN_EQSP_ARG_LEN
#define KERN_SLEN_ARGS_CPX_2S_1	KERN_SLOW_ARGS_CPX_2S_1, KERN_SLOW_ARG_LEN

#define KERN_FAST_ARGS_1S_1	KERN_FAST_ARGS_1, KERN_ARGS_1S
#define KERN_EQSP_ARGS_1S_1	KERN_EQSP_ARGS_1, KERN_ARGS_1S
#define KERN_SLOW_ARGS_1S_1	KERN_SLOW_ARGS_1, KERN_ARGS_1S

#define KERN_FAST_ARGS_1S_2	KERN_FAST_ARGS_2, KERN_ARGS_1S
#define KERN_EQSP_ARGS_1S_2	KERN_EQSP_ARGS_2, KERN_ARGS_1S
#define KERN_SLOW_ARGS_1S_2	KERN_SLOW_ARGS_2, KERN_ARGS_1S

#define KERN_FLEN_ARGS_1S_1	KERN_FAST_ARGS_1S_1, KERN_FAST_ARG_LEN
#define KERN_ELEN_ARGS_1S_1	KERN_EQSP_ARGS_1S_1, KERN_EQSP_ARG_LEN
#define KERN_SLEN_ARGS_1S_1	KERN_SLOW_ARGS_1S_1, KERN_SLOW_ARG_LEN

#define KERN_FLEN_ARGS_1S_2	KERN_FAST_ARGS_1S_2, KERN_FAST_ARG_LEN
#define KERN_ELEN_ARGS_1S_2	KERN_EQSP_ARGS_1S_2, KERN_EQSP_ARG_LEN
#define KERN_SLEN_ARGS_1S_2	KERN_SLOW_ARGS_1S_2, KERN_SLOW_ARG_LEN

#define KERN_FLEN_ARGS_1S_4	KERN_FAST_ARGS_1S_4, KERN_FAST_ARG_LEN
#define KERN_ELEN_ARGS_1S_4	KERN_EQSP_ARGS_1S_4, KERN_EQSP_ARG_LEN
#define KERN_SLEN_ARGS_1S_4	KERN_SLOW_ARGS_1S_4, KERN_SLOW_ARG_LEN

#define KERN_FLEN_ARGS_2S_1	KERN_FAST_ARGS_2S_1, KERN_FAST_ARG_LEN
#define KERN_ELEN_ARGS_2S_1	KERN_EQSP_ARGS_2S_1, KERN_EQSP_ARG_LEN
#define KERN_SLEN_ARGS_2S_1	KERN_SLOW_ARGS_2S_1, KERN_SLOW_ARG_LEN

#define KERN_FLEN_ARGS_2S_3	KERN_FAST_ARGS_2S_3, KERN_FAST_ARG_LEN
#define KERN_ELEN_ARGS_2S_3	KERN_EQSP_ARGS_2S_3, KERN_EQSP_ARG_LEN
#define KERN_SLEN_ARGS_2S_3	KERN_SLOW_ARGS_2S_3, KERN_SLOW_ARG_LEN

#define KERN_FLEN_ARGS_3S_2	KERN_FAST_ARGS_3S_2, KERN_FAST_ARG_LEN
#define KERN_ELEN_ARGS_3S_2	KERN_EQSP_ARGS_3S_2, KERN_EQSP_ARG_LEN
#define KERN_SLEN_ARGS_3S_2	KERN_SLOW_ARGS_3S_2, KERN_SLOW_ARG_LEN

#define KERN_FLEN_ARGS_3S_1	KERN_FAST_ARGS_3S_1, KERN_FAST_ARG_LEN
#define KERN_ELEN_ARGS_3S_1	KERN_EQSP_ARGS_3S_1, KERN_EQSP_ARG_LEN
#define KERN_SLEN_ARGS_3S_1	KERN_SLOW_ARGS_3S_1, KERN_SLOW_ARG_LEN

#define KERN_FAST_ARGS_1S_4	KERN_FAST_ARGS_4, KERN_ARGS_1S
#define KERN_EQSP_ARGS_1S_4	KERN_EQSP_ARGS_4, KERN_ARGS_1S
#define KERN_SLOW_ARGS_1S_4	KERN_SLOW_ARGS_4, KERN_ARGS_1S

#define KERN_FAST_ARGS_2S_1	KERN_FAST_ARGS_1, KERN_ARGS_2S
#define KERN_EQSP_ARGS_2S_1	KERN_EQSP_ARGS_1, KERN_ARGS_2S
#define KERN_SLOW_ARGS_2S_1	KERN_SLOW_ARGS_1, KERN_ARGS_2S

#define KERN_FAST_ARGS_2S_3	KERN_FAST_ARGS_3, KERN_ARGS_2S
#define KERN_EQSP_ARGS_2S_3	KERN_EQSP_ARGS_3, KERN_ARGS_2S
#define KERN_SLOW_ARGS_2S_3	KERN_SLOW_ARGS_3, KERN_ARGS_2S

#define KERN_FAST_ARGS_3S_2	KERN_FAST_ARGS_2, KERN_ARGS_3S
#define KERN_EQSP_ARGS_3S_2	KERN_EQSP_ARGS_2, KERN_ARGS_3S
#define KERN_SLOW_ARGS_3S_2	KERN_SLOW_ARGS_2, KERN_ARGS_3S

#define KERN_FAST_ARGS_3S_1	KERN_FAST_ARGS_1, KERN_ARGS_3S
#define KERN_EQSP_ARGS_3S_1	KERN_EQSP_ARGS_1, KERN_ARGS_3S
#define KERN_SLOW_ARGS_3S_1	KERN_SLOW_ARGS_1, KERN_ARGS_3S

#define KERN_FAST_ARGS_SBM	bitmap_word *bm , int bit0
#define KERN_EQSP_ARGS_SBM	bitmap_word *bm , int bit0 , int bm_inc
#define KERN_SLOW_ARGS_SBM	bitmap_word *bm , int bit0 , dim3 bm_inc

#define KERN_FAST_ARGS_DBM	bitmap_word *bm , int bit0
#define KERN_EQSP_ARGS_DBM	bitmap_word *bm , int bit0 , int bm_inc
#define KERN_SLOW_ARGS_DBM	bitmap_word *bm , int bit0 , dim3 bm_inc

#define KERN_FAST_ARGS_DBM_2SRCS	KERN_FAST_ARGS_DBM, KERN_FAST_ARGS_2SRCS
#define KERN_EQSP_ARGS_DBM_2SRCS	KERN_EQSP_ARGS_DBM, KERN_EQSP_ARGS_2SRCS
#define KERN_SLOW_ARGS_DBM_2SRCS	KERN_SLOW_ARGS_DBM, KERN_SLOW_ARGS_2SRCS

#define KERN_FAST_ARGS_DBM_1S_		KERN_FAST_ARGS_DBM, KERN_ARGS_1S
#define KERN_EQSP_ARGS_DBM_1S_		KERN_EQSP_ARGS_DBM, KERN_ARGS_1S
#define KERN_SLOW_ARGS_DBM_1S_		KERN_SLOW_ARGS_DBM, KERN_ARGS_1S
#define KERN_FAST_ARGS_DBM_1S_1SRC	KERN_FAST_ARGS_DBM, KERN_FAST_ARGS_1SRC, KERN_ARGS_1S
#define KERN_EQSP_ARGS_DBM_1S_1SRC	KERN_EQSP_ARGS_DBM, KERN_EQSP_ARGS_1SRC, KERN_ARGS_1S
#define KERN_SLOW_ARGS_DBM_1S_1SRC	KERN_SLOW_ARGS_DBM, KERN_SLOW_ARGS_1SRC, KERN_ARGS_1S

#define KERN_FAST_ARGS_DBM_1SRC		KERN_FAST_ARGS_DBM, KERN_FAST_ARGS_1SRC
#define KERN_EQSP_ARGS_DBM_1SRC		KERN_EQSP_ARGS_DBM, KERN_EQSP_ARGS_1SRC
#define KERN_SLOW_ARGS_DBM_1SRC		KERN_SLOW_ARGS_DBM, KERN_SLOW_ARGS_1SRC

#define KERN_FAST_ARGS_SBM_1	KERN_FAST_ARGS_1, KERN_FAST_ARGS_SBM
#define KERN_EQSP_ARGS_SBM_1	KERN_EQSP_ARGS_1, KERN_EQSP_ARGS_SBM
#define KERN_SLOW_ARGS_SBM_1	KERN_SLOW_ARGS_1, KERN_SLOW_ARGS_SBM

#define KERN_FAST_ARGS_SBM_3	KERN_FAST_ARGS_3, KERN_FAST_ARGS_SBM
#define KERN_EQSP_ARGS_SBM_3	KERN_EQSP_ARGS_3, KERN_EQSP_ARGS_SBM
#define KERN_SLOW_ARGS_SBM_3	KERN_SLOW_ARGS_3, KERN_SLOW_ARGS_SBM

#define KERN_FAST_ARGS_SBM_CPX_3	KERN_FAST_ARGS_CPX_3, KERN_FAST_ARGS_SBM
#define KERN_EQSP_ARGS_SBM_CPX_3	KERN_EQSP_ARGS_CPX_3, KERN_EQSP_ARGS_SBM
#define KERN_SLOW_ARGS_SBM_CPX_3	KERN_SLOW_ARGS_CPX_3, KERN_SLOW_ARGS_SBM

#define KERN_FAST_ARGS_SBM_CPX_1S_2	KERN_FAST_ARGS_CPX_1S_2, KERN_FAST_ARGS_SBM
#define KERN_EQSP_ARGS_SBM_CPX_1S_2	KERN_EQSP_ARGS_CPX_1S_2, KERN_EQSP_ARGS_SBM
#define KERN_SLOW_ARGS_SBM_CPX_1S_2	KERN_SLOW_ARGS_CPX_1S_2, KERN_SLOW_ARGS_SBM

#define KERN_FAST_ARGS_SBM_CPX_2S_1	KERN_FAST_ARGS_CPX_2S_1, KERN_FAST_ARGS_SBM
#define KERN_EQSP_ARGS_SBM_CPX_2S_1	KERN_EQSP_ARGS_CPX_2S_1, KERN_EQSP_ARGS_SBM
#define KERN_SLOW_ARGS_SBM_CPX_2S_1	KERN_SLOW_ARGS_CPX_2S_1, KERN_SLOW_ARGS_SBM

#define KERN_FAST_ARGS_SBM_1S_2	KERN_FAST_ARGS_1S_2, KERN_FAST_ARGS_SBM
#define KERN_EQSP_ARGS_SBM_1S_2	KERN_EQSP_ARGS_1S_2, KERN_EQSP_ARGS_SBM
#define KERN_SLOW_ARGS_SBM_1S_2	KERN_SLOW_ARGS_1S_2, KERN_SLOW_ARGS_SBM

#define KERN_FAST_ARGS_SBM_2S_1	KERN_FAST_ARGS_2S_1, KERN_FAST_ARGS_SBM
#define KERN_EQSP_ARGS_SBM_2S_1	KERN_EQSP_ARGS_2S_1, KERN_EQSP_ARGS_SBM
#define KERN_SLOW_ARGS_SBM_2S_1	KERN_SLOW_ARGS_2S_1, KERN_SLOW_ARGS_SBM

#define KERN_FLEN_ARGS_SBM_1	KERN_FAST_ARGS_SBM_1, KERN_FAST_ARG_LEN
#define KERN_ELEN_ARGS_SBM_1	KERN_EQSP_ARGS_SBM_1, KERN_EQSP_ARG_LEN
#define KERN_SLEN_ARGS_SBM_1	KERN_SLOW_ARGS_SBM_1, KERN_SLOW_ARG_LEN

#define KERN_FLEN_ARGS_SBM_3	KERN_FAST_ARGS_SBM_3, KERN_FAST_ARG_LEN
#define KERN_ELEN_ARGS_SBM_3	KERN_EQSP_ARGS_SBM_3, KERN_EQSP_ARG_LEN
#define KERN_SLEN_ARGS_SBM_3	KERN_SLOW_ARGS_SBM_3, KERN_SLOW_ARG_LEN

#define KERN_FLEN_ARGS_SBM_CPX_3	KERN_FAST_ARGS_SBM_CPX_3, KERN_FAST_ARG_LEN
#define KERN_ELEN_ARGS_SBM_CPX_3	KERN_EQSP_ARGS_SBM_CPX_3, KERN_EQSP_ARG_LEN
#define KERN_SLEN_ARGS_SBM_CPX_3	KERN_SLOW_ARGS_SBM_CPX_3, KERN_SLOW_ARG_LEN

#define KERN_FLEN_ARGS_SBM_CPX_1S_2	KERN_FAST_ARGS_SBM_CPX_1S_2, KERN_FAST_ARG_LEN
#define KERN_ELEN_ARGS_SBM_CPX_1S_2	KERN_EQSP_ARGS_SBM_CPX_1S_2, KERN_EQSP_ARG_LEN
#define KERN_SLEN_ARGS_SBM_CPX_1S_2	KERN_SLOW_ARGS_SBM_CPX_1S_2, KERN_SLOW_ARG_LEN

#define KERN_FLEN_ARGS_SBM_CPX_2S_1	KERN_FAST_ARGS_SBM_CPX_2S_1, KERN_FAST_ARG_LEN
#define KERN_ELEN_ARGS_SBM_CPX_2S_1	KERN_EQSP_ARGS_SBM_CPX_2S_1, KERN_EQSP_ARG_LEN
#define KERN_SLEN_ARGS_SBM_CPX_2S_1	KERN_SLOW_ARGS_SBM_CPX_2S_1, KERN_SLOW_ARG_LEN

#define KERN_FLEN_ARGS_SBM_1S_2	KERN_FAST_ARGS_SBM_1S_2, KERN_FAST_ARG_LEN
#define KERN_ELEN_ARGS_SBM_1S_2	KERN_EQSP_ARGS_SBM_1S_2, KERN_EQSP_ARG_LEN
#define KERN_SLEN_ARGS_SBM_1S_2	KERN_SLOW_ARGS_SBM_1S_2, KERN_SLOW_ARG_LEN

#define KERN_FLEN_ARGS_SBM_2S_1	KERN_FAST_ARGS_SBM_2S_1, KERN_FAST_ARG_LEN
#define KERN_ELEN_ARGS_SBM_2S_1	KERN_EQSP_ARGS_SBM_2S_1, KERN_EQSP_ARG_LEN
#define KERN_SLEN_ARGS_SBM_2S_1	KERN_SLOW_ARGS_SBM_2S_1, KERN_SLOW_ARG_LEN

#define KERN_FLEN_ARGS_DBM_2SRCS	KERN_FAST_ARGS_DBM_2SRCS, KERN_FAST_ARG_LEN
#define KERN_ELEN_ARGS_DBM_2SRCS	KERN_EQSP_ARGS_DBM_2SRCS, KERN_EQSP_ARG_LEN
#define KERN_SLEN_ARGS_DBM_2SRCS	KERN_SLOW_ARGS_DBM_2SRCS, KERN_SLOW_ARG_LEN

#define KERN_FLEN_ARGS_DBM_1S_		KERN_FAST_ARGS_DBM_1S_, KERN_FAST_ARG_LEN
#define KERN_ELEN_ARGS_DBM_1S_		KERN_EQSP_ARGS_DBM_1S_, KERN_EQSP_ARG_LEN
#define KERN_SLEN_ARGS_DBM_1S_		KERN_SLOW_ARGS_DBM_1S_, KERN_SLOW_ARG_LEN
#define KERN_FLEN_ARGS_DBM_1S_1SRC	KERN_FAST_ARGS_DBM_1S_1SRC, KERN_FAST_ARG_LEN
#define KERN_ELEN_ARGS_DBM_1S_1SRC	KERN_EQSP_ARGS_DBM_1S_1SRC, KERN_EQSP_ARG_LEN
#define KERN_SLEN_ARGS_DBM_1S_1SRC	KERN_SLOW_ARGS_DBM_1S_1SRC, KERN_SLOW_ARG_LEN

#define KERN_FLEN_ARGS_DBM_1SRC		KERN_FAST_ARGS_DBM_1SRC, KERN_FAST_ARG_LEN
#define KERN_ELEN_ARGS_DBM_1SRC		KERN_EQSP_ARGS_DBM_1SRC, KERN_EQSP_ARG_LEN
#define KERN_SLEN_ARGS_DBM_1SRC		KERN_SLOW_ARGS_DBM_1SRC, KERN_SLOW_ARG_LEN


/****************** DECL_INDICES ***********************/

#define DECL_INDICES_1		dim3 index1;
#define DECL_INDICES_SRC1	dim3 index2;
#define DECL_INDICES_SRC2	dim3 index3;
#define DECL_INDICES_SRC3	dim3 index4;
#define DECL_INDICES_SRC4	dim3 index5;
#define DECL_INDICES_SBM	dim3 bmi;

#define DECL_INDICES_DBM	dim3 bmi; int i_bit;	\
				int i_word; bitmap_word bit;

#define DECL_INDICES_2		DECL_INDICES_1 DECL_INDICES_SRC1
#define DECL_INDICES_3		DECL_INDICES_2 DECL_INDICES_SRC2
#define DECL_INDICES_4		DECL_INDICES_3 DECL_INDICES_SRC3
#define DECL_INDICES_5		DECL_INDICES_4 DECL_INDICES_SRC4
#define DECL_INDICES_1SRC	DECL_INDICES_SRC1
#define DECL_INDICES_2SRCS	DECL_INDICES_SRC1 DECL_INDICES_SRC2
#define DECL_INDICES_SBM_1	DECL_INDICES_1 DECL_INDICES_SBM
#define DECL_INDICES_SBM_2	DECL_INDICES_2 DECL_INDICES_SBM
#define DECL_INDICES_SBM_3	DECL_INDICES_3 DECL_INDICES_SBM

#define DECL_INDICES_DBM_	DECL_INDICES_DBM
#define DECL_INDICES_DBM_1SRC	DECL_INDICES_1SRC DECL_INDICES_DBM
#define DECL_INDICES_DBM_2SRCS	DECL_INDICES_2SRCS DECL_INDICES_DBM


#define DECL_SPECIAL_
#define DECL_SPECIAL_T	std_type std_tmp;
#define DECL_SPECIAL_D	std_type std_tmp, tmp_denom;

/*********************** INIT_INDICES *****************/

#define INIT_INDICES_1		DECL_INDICES_1 SET_INDICES_1
#define INIT_INDICES_2		DECL_INDICES_2 SET_INDICES_2
#define INIT_INDICES_2		DECL_INDICES_2 SET_INDICES_2
#define INIT_INDICES_3		DECL_INDICES_3 SET_INDICES_3
#define INIT_INDICES_4		DECL_INDICES_4 SET_INDICES_4
#define INIT_INDICES_5		DECL_INDICES_5 SET_INDICES_5

#define INIT_INDICES_2SRCS	DECL_INDICES_2SRCS SET_INDICES_2SRCS
#define INIT_INDICES_SBM_1	DECL_INDICES_SBM_1 SET_INDICES_SBM_1
#define INIT_INDICES_SBM_2	DECL_INDICES_SBM_2 SET_INDICES_SBM_2
#define INIT_INDICES_SBM_3	DECL_INDICES_SBM_3 SET_INDICES_SBM_3

#define INIT_INDICES_DBM_	DECL_INDICES_DBM_ SET_INDICES_DBM_
#define INIT_INDICES_DBM_2SRCS	DECL_INDICES_DBM_2SRCS SET_INDICES_DBM_2SRCS
#define INIT_INDICES_DBM_1SRC	DECL_INDICES_DBM_1SRC SET_INDICES_DBM_1SRC

#define INIT_INDICES_XY_1	DECL_INDICES_1 SET_INDICES_XY_1
#define INIT_INDICES_XY_2	DECL_INDICES_2 SET_INDICES_XY_2
#define INIT_INDICES_XY_3	DECL_INDICES_3 SET_INDICES_XY_3
#define INIT_INDICES_XY_4	DECL_INDICES_4 SET_INDICES_XY_4
#define INIT_INDICES_XY_5	DECL_INDICES_5 SET_INDICES_XY_5

#define INIT_INDICES_XY_SBM_1	DECL_INDICES_SBM_1 SET_INDICES_XY_SBM_1
#define INIT_INDICES_XY_SBM_2	DECL_INDICES_SBM_2 SET_INDICES_XY_SBM_2
#define INIT_INDICES_XY_SBM_3	DECL_INDICES_SBM_3 SET_INDICES_XY_SBM_3

#define INIT_INDICES_XY_DBM_		DECL_INDICES_DBM_ SET_INDICES_XY_DBM_
#define INIT_INDICES_XY_DBM_1SRC	DECL_INDICES_DBM_1SRC SET_INDICES_XY_DBM_1SRC
#define INIT_INDICES_XY_DBM_2SRCS	DECL_INDICES_DBM_2SRCS SET_INDICES_XY_DBM_2SRCS


#define INIT_INDICES_XYZ_1	DECL_INDICES_1 SET_INDICES_XYZ_1
#define INIT_INDICES_XYZ_2	DECL_INDICES_2 SET_INDICES_XYZ_2
#define INIT_INDICES_XYZ_3	DECL_INDICES_3 SET_INDICES_XYZ_3
#define INIT_INDICES_XYZ_4	DECL_INDICES_4 SET_INDICES_XYZ_4
#define INIT_INDICES_XYZ_5	DECL_INDICES_5 SET_INDICES_XYZ_5

#define INIT_INDICES_XYZ_SBM_1	DECL_INDICES_SBM_1 SET_INDICES_XYZ_SBM_1
#define INIT_INDICES_XYZ_SBM_2	DECL_INDICES_SBM_2 SET_INDICES_XYZ_SBM_2
#define INIT_INDICES_XYZ_SBM_3	DECL_INDICES_SBM_3 SET_INDICES_XYZ_SBM_3

#define INIT_INDICES_XYZ_DBM_		DECL_INDICES_DBM_ SET_INDICES_XYZ_DBM_
#define INIT_INDICES_XYZ_DBM_1SRC	DECL_INDICES_DBM_1SRC SET_INDICES_XYZ_DBM_1SRC
#define INIT_INDICES_XYZ_DBM_2SRCS	DECL_INDICES_DBM_2SRCS SET_INDICES_XYZ_DBM_2SRCS


/******************** SET_INDICES ***************************/

#define SET_INDEX( which_index )					\
									\
		which_index.x = blockIdx.x * blockDim.x + threadIdx.x;	\
		which_index.y = which_index.z = 0;

#define SET_INDICES_1		SET_INDEX( index1 )
#define SET_INDICES_SRC1	index2 = index1;
#define SET_INDICES_SRC2	index3 = index2;
#define SET_INDICES_SRC3	index4 = index3;
#define SET_INDICES_SRC4	index5 = index4;
#define SET_INDICES_SBM		bmi = index1;

#define SET_INDICES_2		SET_INDICES_1 SET_INDICES_SRC1
#define SET_INDICES_3		SET_INDICES_2 SET_INDICES_SRC2
#define SET_INDICES_4		SET_INDICES_3 SET_INDICES_SRC3
#define SET_INDICES_5		SET_INDICES_4 SET_INDICES_SRC4
#define SET_INDICES_2SRCS	SET_INDEX(index2) SET_INDICES_SRC2


#define SET_INDICES_SBM_1	SET_INDICES_1 SET_INDICES_SBM
#define SET_INDICES_SBM_2	SET_INDICES_2 SET_INDICES_SBM
#define SET_INDICES_SBM_3	SET_INDICES_3 SET_INDICES_SBM

#define SET_INDICES_DBM		SET_INDEX(bmi)				\
				bmi.x *= BITS_PER_BITMAP_WORD;

#define SET_INDICES_DBM_	SET_INDICES_DBM
#define SET_INDICES_1SRC	index2 = bmi;

#define SET_INDICES_DBM_1SRC	SET_INDICES_DBM SET_INDICES_1SRC
#define SET_INDICES_DBM_2SRCS	SET_INDICES_DBM_1SRC SET_INDICES_SRC2

/**************************** SET_INDICES_XY ******************************/

#define SET_INDEX_XY( which_index )					\
									\
	which_index.x = blockIdx.x * blockDim.x + threadIdx.x;		\
	which_index.y = blockIdx.y * blockDim.y + threadIdx.y;		\
	which_index.z = 0;


#define SET_INDICES_XY_1	SET_INDEX_XY(index1)
#define SET_INDICES_XY_SRC1	index2 = index1;
#define SET_INDICES_XY_SRC2	index3 = index2;
#define SET_INDICES_XY_SRC3	index4 = index1;
#define SET_INDICES_XY_SRC4	index5 = index1;
#define SET_INDICES_XY_2	SET_INDICES_XY_1 SET_INDICES_XY_SRC1
#define SET_INDICES_XY_3	SET_INDICES_XY_2 SET_INDICES_XY_SRC2
#define SET_INDICES_XY_4	SET_INDICES_XY_3 SET_INDICES_XY_SRC3
#define SET_INDICES_XY_5	SET_INDICES_XY_4 SET_INDICES_XY_SRC4
#define SET_INDICES_XY_1SRC	SET_INDEX_XY(index2)
#define SET_INDICES_XY_2SRCS	SET_INDICES_XY_1SRC SET_INDICES_XY_SRC2
#define SET_INDICES_XY_SBM_1	SET_INDICES_XY_1 SET_INDICES_XY_SBM
#define SET_INDICES_XY_SBM_2	SET_INDICES_XY_2 SET_INDICES_XY_SBM
#define SET_INDICES_XY_SBM_3	SET_INDICES_XY_3 SET_INDICES_XY_SBM
#define SET_INDICES_XY_DBM_	SET_INDICES_XY_DBM
#define SET_INDICES_XY_DBM_1SRC	SET_INDICES_XY_DBM index2=bmi;
#define SET_INDICES_XY_DBM_2SRCS	SET_INDICES_XY_DBM_1SRC SET_INDICES_XY_SRC2

/* BUG? is bmi set correctly? Is len.x the divided length?  or all the pixels? */
#define SET_INDICES_XY_SBM	bmi = index1;
#define SET_INDICES_XY_DBM	SET_INDEX_XY(bmi)	\
				bmi.x *= BITS_PER_BITMAP_WORD;


#define SET_INDEX_XYZ( which_index )					\
									\
	which_index.x = blockIdx.x * blockDim.x + threadIdx.x;		\
	which_index.y = blockIdx.y * blockDim.y + threadIdx.y;		\
	which_index.z = blockIdx.z * blockDim.z + threadIdx.z;


#define SET_INDICES_XYZ_1	SET_INDEX_XYZ(index1)
#define SET_INDICES_XYZ_SRC1	index2 = index1;
#define SET_INDICES_XYZ_SRC2	index3 = index2;
#define SET_INDICES_XYZ_SRC3	index4 = index1;
#define SET_INDICES_XYZ_SRC4	index5 = index1;
#define SET_INDICES_XYZ_2	SET_INDICES_XYZ_1 SET_INDICES_XYZ_SRC1
#define SET_INDICES_XYZ_3	SET_INDICES_XYZ_2 SET_INDICES_XYZ_SRC2
#define SET_INDICES_XYZ_4	SET_INDICES_XYZ_3 SET_INDICES_XYZ_SRC3
#define SET_INDICES_XYZ_5	SET_INDICES_XYZ_4 SET_INDICES_XYZ_SRC4
#define SET_INDICES_XYZ_1SRC	SET_INDEX_XYZ(index2)
#define SET_INDICES_XYZ_2SRCS	SET_INDICES_XYZ_1SRC SET_INDICES_XYZ_SRC2
#define SET_INDICES_XYZ_SBM_1	SET_INDICES_XYZ_1 SET_INDICES_XYZ_SBM
#define SET_INDICES_XYZ_SBM_2	SET_INDICES_XYZ_2 SET_INDICES_XYZ_SBM
#define SET_INDICES_XYZ_SBM_3	SET_INDICES_XYZ_3 SET_INDICES_XYZ_SBM
#define SET_INDICES_XYZ_DBM_	SET_INDICES_XYZ_DBM
#define SET_INDICES_XYZ_DBM_1SRC	SET_INDICES_XYZ_DBM index2=bmi;
#define SET_INDICES_XYZ_DBM_2SRCS	SET_INDICES_XYZ_DBM_1SRC SET_INDICES_XYZ_SRC2

/* BUG? is bmi set correctly? Is len.x the divided length?  or all the pixels? */
#define SET_INDICES_XYZ_SBM	bmi = index1;
#define SET_INDICES_XYZ_DBM	SET_INDEX_XYZ(bmi)	\
				bmi.x *= BITS_PER_BITMAP_WORD;

/**************** SCALE_INDICES_ ********************/

#define SCALE_INDICES_1		index1.x *= inc1;
#define SCALE_INDICES_SRC1	index2.x *= inc2;
#define SCALE_INDICES_SRC2	index3.x *= inc3;
#define SCALE_INDICES_SRC3	index4.x *= inc4;
#define SCALE_INDICES_SRC4	index5.x *= inc5;
#define SCALE_INDICES_SBM	bmi.x *= bm_inc;
#define SCALE_INDICES_DBM	bmi.x *= bm_inc;

#define SCALE_INDICES_2		SCALE_INDICES_1 SCALE_INDICES_SRC1
#define SCALE_INDICES_3		SCALE_INDICES_2 SCALE_INDICES_SRC2
#define SCALE_INDICES_4		SCALE_INDICES_3 SCALE_INDICES_SRC3
#define SCALE_INDICES_5		SCALE_INDICES_4 SCALE_INDICES_SRC4


#define SCALE_XY(n)	index##n.x *= inc##n.x;		\
			index##n.y *= inc##n.y;

#define SCALE_INDICES_XY_1	SCALE_XY(1)
#define SCALE_INDICES_XY_2	SCALE_INDICES_XY_1 SCALE_XY(2)
#define SCALE_INDICES_XY_3	SCALE_INDICES_XY_2 SCALE_XY(3)
#define SCALE_INDICES_XY_4	SCALE_INDICES_XY_3 SCALE_XY(4)
#define SCALE_INDICES_XY_5	SCALE_INDICES_XY_4 SCALE_XY(5)
#define SCALE_INDICES_XY_SBM	bmi.x *= bm_inc.x;	\
				bmi.y *= bm_inc.y;

#define SCALE_INDICES_XY_DBM	bmi.x *= bm_inc.x;		\
				if( bmi.y >= len.y ) return;	\
				bmi.y *= bm_inc.y;

#define SCALE_INDICES_XY_2SRCS		SCALE_XY(2) SCALE_XY(3)
#define SCALE_INDICES_XY_DBM_		SCALE_INDICES_XY_DBM
#define SCALE_INDICES_XY_DBM_1SRC	SCALE_INDICES_XY_DBM SCALE_XY(2)
#define SCALE_INDICES_XY_DBM_2SRCS	SCALE_INDICES_XY_DBM		\
					SCALE_INDICES_XY_2SRCS

#define SCALE_INDICES_XY_SBM_1		SCALE_INDICES_XY_SBM SCALE_INDICES_XY_1
#define SCALE_INDICES_XY_SBM_2		SCALE_INDICES_XY_SBM SCALE_INDICES_XY_2
#define SCALE_INDICES_XY_SBM_3		SCALE_INDICES_XY_SBM SCALE_INDICES_XY_3



#define SCALE_XYZ(n)	index##n.x *= inc##n.x;		\
			index##n.y *= inc##n.y;		\
			index##n.z *= inc##n.z;

#define SCALE_INDICES_XYZ_1	SCALE_XYZ(1)
#define SCALE_INDICES_XYZ_2	SCALE_INDICES_XYZ_1 SCALE_XYZ(2)
#define SCALE_INDICES_XYZ_3	SCALE_INDICES_XYZ_2 SCALE_XYZ(3)
#define SCALE_INDICES_XYZ_4	SCALE_INDICES_XYZ_3 SCALE_XYZ(4)
#define SCALE_INDICES_XYZ_5	SCALE_INDICES_XYZ_4 SCALE_XYZ(5)
#define SCALE_INDICES_XYZ_SBM	bmi.x *= bm_inc.x;	\
				bmi.y *= bm_inc.y;	\
				bmi.z *= bm_inc.z;

#define SCALE_INDICES_XYZ_DBM	bmi.x *= bm_inc.x;		\
				if( bmi.y >= len.y ) return;	\
				bmi.y *= bm_inc.y;

#define SCALE_INDICES_XYZ_2SRCS		SCALE_XYZ(2) SCALE_XYZ(3)
#define SCALE_INDICES_XYZ_DBM_		SCALE_INDICES_XYZ_DBM
#define SCALE_INDICES_XYZ_DBM_1SRC	SCALE_INDICES_XYZ_DBM SCALE_XYZ(2)
#define SCALE_INDICES_XYZ_DBM_2SRCS	SCALE_INDICES_XYZ_DBM		\
					SCALE_INDICES_XYZ_2SRCS

#define SCALE_INDICES_XYZ_SBM_1		SCALE_INDICES_XYZ_SBM SCALE_INDICES_XYZ_1
#define SCALE_INDICES_XYZ_SBM_2		SCALE_INDICES_XYZ_SBM SCALE_INDICES_XYZ_2
#define SCALE_INDICES_XYZ_SBM_3		SCALE_INDICES_XYZ_SBM SCALE_INDICES_XYZ_3


/* These are used in DBM kernels, where we need to scale the bitmap index
 * even in fast loops
 */

#define SCALE_INDICES_FAST_1	/* nop */
#define SCALE_INDICES_FAST_2	/* nop */
#define SCALE_INDICES_FAST_3	/* nop */
#define SCALE_INDICES_FAST_4	/* nop */
#define SCALE_INDICES_FAST_5	/* nop */

#define SCALE_INDICES_EQSP_1	SCALE_INDICES_1
#define SCALE_INDICES_EQSP_2	SCALE_INDICES_2
#define SCALE_INDICES_EQSP_3	SCALE_INDICES_3
#define SCALE_INDICES_EQSP_4	SCALE_INDICES_4
#define SCALE_INDICES_EQSP_5	SCALE_INDICES_5
#define SCALE_INDICES_EQSP_1SRC	SCALE_INDICES_SRC1
#define SCALE_INDICES_EQSP_2SRCS	SCALE_INDICES_SRC1 SCALE_INDICES_SRC2
#define SCALE_INDICES_EQSP_SBM	SCALE_INDICES_SBM
#define SCALE_INDICES_EQSP_DBM	SCALE_INDICES_DBM

#define SCALE_INDICES_EQSP_SBM_1	SCALE_INDICES_EQSP_1 SCALE_INDICES_EQSP_SBM
#define SCALE_INDICES_EQSP_SBM_2	SCALE_INDICES_EQSP_2 SCALE_INDICES_EQSP_SBM
#define SCALE_INDICES_EQSP_SBM_3	SCALE_INDICES_EQSP_3 SCALE_INDICES_EQSP_SBM
#define SCALE_INDICES_EQSP_DBM_		SCALE_INDICES_EQSP_DBM
#define SCALE_INDICES_EQSP_DBM_1SRC	SCALE_INDICES_EQSP_1SRC SCALE_INDICES_EQSP_DBM
#define SCALE_INDICES_EQSP_DBM_2SRCS	SCALE_INDICES_EQSP_2SRCS SCALE_INDICES_EQSP_DBM

/*************************************************************/

//#define dst	a[index1.x+index1.y]
#if CUDA_COMP_CAP < 20
#define dst	a[index1.x+index1.y+index1.z]
#define src1	b[index2.x+index2.y]
#define src2	c[index3.x+index3.y]
#define src3	d[index4.x+index4.y]
#define src4	e[index5.x+index5.y]
#define srcbit	(bm[(bmi.x+bmi.y+bit0)>>LOG2_BITS_PER_BITMAP_WORD] & \
			NUMBERED_BIT((bmi.x+bmi.y+bit0)&(BITS_PER_BITMAP_WORD-1)))

#define cdst	a[index1.x+index1.y]
#define csrc1	b[index2.x+index2.y]
#define csrc2	c[index3.x+index3.y]
#define csrc3	d[index4.x+index4.y]
#define csrc4	e[index5.x+index5.y]

#else /* CUDA_COMP_CAP >= 20 */

/* Can do XYZ indexing */

#define dst	a[index1.x+index1.y+index1.z]
#define src1	b[index2.x+index2.y+index2.z]
#define src2	c[index3.x+index3.y+index3.z]
#define src3	d[index4.x+index4.y+index4.z]
#define src4	e[index5.x+index5.y+index5.z]
#define srcbit	(bm[(bmi.x+bmi.y+bmi.z+bit0)>>LOG2_BITS_PER_BITMAP_WORD] & \
		NUMBERED_BIT((bmi.x+bmi.y+bmi.z+bit0)&(BITS_PER_BITMAP_WORD-1)))

#define cdst	a[index1.x+index1.y+index1.z]
#define csrc1	b[index2.x+index2.y+index2.z]
#define csrc2	c[index3.x+index3.y+index3.z]
#define csrc3	d[index4.x+index4.y+index4.z]
#define csrc4	e[index5.x+index5.y+index5.z]

#endif /* CUDA_COMP_CAP >= 20 */


#define SETBIT(cond)	if( cond ) bm[i_word] |= bit; else bm[i_word] &= ~bit;


