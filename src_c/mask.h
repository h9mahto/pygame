#ifndef PGMASK_H
#define PGMASK_H

#include <Python.h>
#include "bitmask.h"

#define PYGAMEAPI_MASK_FIRSTSLOT 0
#define PYGAMEAPI_MASK_NUMSLOTS 1

typedef struct {
  PyObject_HEAD
  bitmask_t *mask;
} pgMaskObject;

#define pgMask_AsBitmap(x) (((pgMaskObject*)x)->mask)

#ifndef PYGAMEAPI_MASK_INTERNAL

#include "pgimport.h"

PYGAMEAPI_DEFINE_SLOTS(PyMASK_C_API, PYGAMEAPI_MASK_NUMSLOTS);

#define pgMask_Type     (*(PyTypeObject*) \
    PYGAMEAPI_GET_SLOT(PyMASK_C_API, 0))
#define pgMask_Check(x) ((x)->ob_type == &pgMask_Type)

#define import_pygame_mask() \
    _IMPORT_PYGAME_MODULE(mask, MASK, PyMASK_C_API)

#endif /* ~PYGAMEAPI_MASK_INTERNAL */

#endif /* ~PGMASK_H */
