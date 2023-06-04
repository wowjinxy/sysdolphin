#include <string.h>

#include "sysdolphin/baselib/aobj.h"
#include "sysdolphin/baselib/fobj.h"

void HSD_AObjInitAllocData()
{
	HSD_ObjAllocInit((HSD_ObjAllocData *)&alloc_data,sizeof(HSD_AObj),4);
}

HSD_ObjAllocData *HSD_AObjGetAllocData(void)
{
    return &alloc_data;
}

u32 HSD_AObjGetFlags(HSD_AObj *aobj)
{
    return (aobj) ? aobj->flags : 0;
}

void HSD_AObjSetFlags(HSD_AObj *aobj, u32 flags)
{
    if (aobj) {
        flags &= (AOBJ_LOOP | AOBJ_NO_UPDATE);
        aobj->flags |= flags;
    }
}

void HSD_AObjClearFlags(HSD_AObj* aobj, u32 flags)
{
    if (aobj) {
        flags &= (AOBJ_LOOP | AOBJ_NO_UPDATE);
        aobj->flags &= ~flags;
    }
}

void HSD_AObjSetFObj(HSD_AObj* aobj, HSD_FObj* fobj)
{
    if (!aobj)
        return;

    if (aobj->fobj)
        HSD_FObjRemoveAll(aobj->fobj);
    aobj->fobj = fobj;
}

void HSD_AObjSetPath(void)
{
	/* To Do */
}

void HSD_AObjInitEndCallBack(void)
{
	/* To Do */
}

void HSD_AObjInvokeCallBacks(void)
{
	/* To Do */
}

void HSD_AObjAddEndCallBack(void)
{
	/* To Do */
}

void HSD_AObjRemoveEndCallBack(void)
{
	/* To Do */
}

void HSD_AObjReqAnim(HSD_AObj* aobj, f32 frame)
{
    u32 flags;

    if (!aobj)
        return;

    aobj->curr_frame = frame;

    flags = aobj->flags & 0xBFFFFFFF;
    aobj->flags = flags | AOBJ_FIRST_PLAY;

    HSD_FObjReqAnimAll(aobj->fobj, frame);
}

void HSD_AObjStopAnim(HSD_AObj* aobj, void* obj, void (*func)())
{
    if (!aobj)
        return;

    HSD_FObjStopAnimAll(aobj->fobj, obj, func, aobj->framerate);
    aobj->flags |= AOBJ_NO_ANIM;
}

void HSD_AObjInterpretAnim(void)
{
	/* To Do */
}

void HSD_AObjLoadDesc(void)
{
	/* To Do */
}

void HSD_AObjRemove(HSD_AObj* aobj)
{
    if (!aobj)
        return;
    
    if (aobj)
	{
        if (aobj->fobj)
            HSD_FObjRemoveAll(aobj->fobj);
        aobj->fobj = NULL;
    }

    if (aobj)
	{
        if (aobj->hsd_obj != NULL)
            HSD_JObjUnref((HSD_JObj*)aobj->hsd_obj);
        aobj->hsd_obj = NULL;
    }
    HSD_AObjFree(aobj);
}

HSD_MObj *HSD_MObjAlloc(void)
{
  HSD_AObj *mobj = hsdNew(HSD_AObjGetDefaultClass());
  assert(aobj);
  return aobj;
}

void HSD_AObjFree(HSD_AObj* aobj)
{
    if (!aobj)
        return;
    
    HSD_ObjFree(&alloc_data, (HSD_ObjAllocLink*)aobj);
}

void callbackForeachFunc(void)
{
	/* To Do */
}

void ChanForeachAnim(void)
{
	/* To Do */
}

void TevRegForeachAnim(void)
{
	/* To Do */
}

void RenderForeachAnim(void)
{
	/* To Do */
}

void FogForeachAnim(void)
{
	/* To Do */
}

void TObjForeachAnim(void)
{
	/* To Do */
}

void RObjForeachAnim(void)
{
	/* To Do */
}

void WObjForeachAnim(void)
{
	/* To Do */
}

void CObjForeachAnim(void)
{
	/* To Do */
}

void LObjForeachAnim(void)
{
	/* To Do */
}

void PObjForeachAnim(void)
{
	/* To Do */
}

void MObjForeachAnim(void)
{
	/* To Do */
}

void DObjForeachAnim(void)
{
	/* To Do */
}

void JObjForeachAnim(void)
{
	/* To Do */
}

void HSD_ForeachAnim(void)
{
	/* To Do */
}

void HSD_AObjSetRate(HSD_AObj* aobj, f32 rate)
{
    if (!aobj)
        return;
    aobj->framerate = rate;
}

void HSD_AObjSetRewindFrame(HSD_AObj* aobj, f32 frame)
{
    if (!aobj)
        return;
    aobj->rewind_frame = frame;
}

void HSD_AObjSetEndFrame(HSD_AObj* aobj, f32 frame)
{
    if (!aobj)
        return;
    aobj->end_frame = frame;
}

void HSD_AObjSetCurrentFrame(HSD_AObj* aobj, f32 frame)
{
    if (!aobj)
        return;

    if (!(aobj->flags & AOBJ_NO_ANIM) && aobj) {
        aobj->curr_frame = frame;
        aobj->flags = (aobj->flags & 0xBFFFFFFF) | AOBJ_FIRST_PLAY;
        HSD_FObjReqAnimAll(aobj->fobj, frame);
    }
}

void _HSD_AObjForgetMemory(void)
{
	/* To Do */
}

void HSD_JObjRef(void)
{
	/* To Do */
}

void ref_INC(void)
{
	/* To Do */
}

void HSD_IDGetData(void)
{
	/* To Do */
}

void dumpObjAlloc(void)
{
	/* To Do */
}