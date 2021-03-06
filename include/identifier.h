#ifndef _IDENTIFIER_H_
#define _IDENTIFIER_H_

#include "item_type.h"	// Item_Context
#include "shape_info.h"
#include "pointer.h"

/* identifier flags */
typedef enum {
	/* ID_OBJECT, */
	ID_POINTER,
	ID_REFERENCE,
	ID_SUBRT,
	ID_STRING,
	ID_FUNCPTR,
	ID_LABEL
} Id_Type;

typedef struct id_data {
	Pointer *	id_ptrp;
	Reference *	id_refp;
} Id_Data;

typedef struct identifier {
	Item		id_item;
	int		id_type;
	void *		id_data;
	Shape_Info *	id_shpp;
	Item_Context *	id_icp;
} Identifier;

/* Identifier */
#define ID_NAME(idp)			(idp)->id_item.item_name

#define ID_TYPE(idp)			(idp)->id_type
#define SET_ID_TYPE(idp,t)		(idp)->id_type = t
#define ID_REF(idp)			((Reference *)(idp)->id_data)
#define SET_ID_REF(idp,refp)		(idp)->id_data = refp
#define ID_FUNC(idp)			((Function_Ptr *)(idp)->id_data)
#define SET_ID_FUNC(idp,funcp)		(idp)->id_data = funcp
#define ID_DOBJ_CTX(idp)		(idp)->id_icp
#define SET_ID_DOBJ_CTX(idp,icp)	(idp)->id_icp = icp
#define ID_PTR(idp)			((Pointer *)(idp)->id_data)
#define SET_ID_PTR(idp,p)		(idp)->id_data = p

#define ID_SHAPE(idp)			(idp)->id_shpp
#define SET_ID_SHAPE(idp,shpp)		(idp)->id_shpp = shpp
#define PUSH_ID_CONTEXT(icp)		PUSH_ITEM_CONTEXT(id_itp,icp)
#define POP_ID_CONTEXT			POP_ITEM_CONTEXT(id_itp)


#define NO_IDENTIFIER	((Identifier *)NULL)

#ifdef FOOBAR
#define id_fpp		id_u.u_fpp
#define id_ptrp		id_u.u_ptrp
/* #define id_dp		id_u.u_dp */
/*#define id_sbp		id_u.u_sbp */
#define id_refp		id_u.u_refp
#endif /* FOOBAR */


#define IS_STRING_ID(idp)	(ID_TYPE(idp) == ID_STRING)
#define IS_POINTER(idp)		(ID_TYPE(idp) == ID_POINTER)
#define IS_REFERENCE(idp)	(ID_TYPE(idp) == ID_REFERENCE)
#define IS_SUBRT(idp)		(ID_TYPE(idp) == ID_SUBRT)
/* #define IS_OBJECT(idp)	(ID_TYPE(idp) == ID_OBJECT) */
#define IS_FUNCPTR(idp)		(ID_TYPE(idp) == ID_FUNCPTR)
#define IS_LABEL(idp)		(ID_TYPE(idp) == ID_LABEL)

#define STRING_IS_SET(idp)	(REF_SBUF(ID_REF(idp))->sb_buf != NULL)
#define POINTER_IS_SET(idp)	(PTR_FLAGS(ID_PTR(idp)) & POINTER_SET)


ITEM_NEW_PROT(Identifier,id)
ITEM_CHECK_PROT(Identifier,id)
ITEM_GET_PROT(Identifier,id)
ITEM_INIT_PROT(Identifier,id)


extern void del_id(QSP_ARG_DECL  Identifier *idp);

extern Item_Context *create_id_context(QSP_ARG_DECL  const char *);
extern void restrict_id_context(QSP_ARG_DECL  int flag);

#define RESTRICT_ID_CONTEXT(flag)	restrict_id_context(QSP_ARG  flag)

#endif /* ! _IDENTIFIER_H_ */

