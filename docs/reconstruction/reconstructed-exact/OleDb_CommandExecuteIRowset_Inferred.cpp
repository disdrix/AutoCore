// =============================================================================
// OleDb_CommandExecuteIRowset_Inferred
// -----------------------------------------------------------------------------
// Purpose:  Optional ICommandProperties::SetProperties, then ICommand::Execute
//           requesting IID_IRowset into *ppRowset (typically ctx+0x10). On
//           success, if *(ctx+0x10) non-null, QI that object for
//           IID_IRowsetChange into ctx+0x14 (HRESULT ignored).
//
// Address:  0x00421aa0  (autoassault.exe, image base 0x400000)
// Body:     0x00421aa0–0x00421b4f
// Stable:   aa_00421aa0
// System:   COM / OLE DB bind-continuation execute
//
// ABI:      EAX = bind context; EBX = DBPROPSET* (null skips SetProperties);
//           stdcall 4 stack args; ret 0x10. Returns HRESULT in EAX.
//
// IIDs (sealed via read_memory + OLE DB GUID catalog):
//   DAT_00a860e8 → IID_ICommandProperties {0C733A79-2A1C-11CE-ADE5-00AA0044773D}
//   DAT_00a8608c → IID_IRowset           {0C733A7C-2A1C-11CE-ADE5-00AA0044773D}
//   DAT_00a860f8 → IID_IRowsetChange     {0C733A05-2A1C-11CE-ADE5-00AA0044773D}
//
// Decompiler residual: Ghidra attributes SetProperties to *param_1; bytes call
// the QI result in the reused 4th stack slot. Clean follows bytes.
//
// Exactness: CF mirrors raw + read_memory; names cleaned / product-inferred.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Dual A/B: accept-with-gaps (2026-07-29 W18-D seal).
// =============================================================================

/* OleDb_CommandExecuteIRowset_Inferred

   Parameters:
     ctx (EAX): bind context with command iface at +0x24, rowset at +0x10,
                IRowsetChange out at +0x14
     rgPropertySets (EBX): non-null enables SetProperties path
     ppRowset: typically &ctx->field_0x10
     pParams: optional execute params / continuation blob
     pcRowsAffected: may be null (stack scratch used)
     cPropertySets: 0 coerced to 1 when properties path runs

   Returns: HRESULT (EAX). */

extern "C" int __stdcall OleDb_CommandExecuteIRowset_Inferred(
    void **ppRowset,
    void *pParams,
    void *pcRowsAffected,
    int cPropertySets,
    /* register formals recovered from bytes / sole caller: */
    void *ctx /*EAX*/,
    void *rgPropertySets /*EBX*/);

// Byte-faithful reconstruction (register formals documented; MSVC stdcall
// cannot express EAX/EBX formals — keep as comments + body logic).

int OleDb_CommandExecuteIRowset_Inferred_Body(
    void *ctx,
    void *rgPropertySets,
    void **ppRowset,
    void *pParams,
    void *pcRowsAffected,
    int cPropertySets)
{
  int hr;
  void *pCmdProps;
  unsigned char scratch_rows[4];
  void *pRowsetObj;
  void *pCmd;

  if (rgPropertySets != 0) {
    int cSets = cPropertySets;
    if (cSets == 0) {
      cSets = 1;
    }

    /* FUN_00437cd0 — zero COM out slot (reuses cPropertySets stack home). */
    pCmdProps = 0;

    pCmd = *(void **)((char *)ctx + 0x24);
    /* vtbl[0] QueryInterface(IID_ICommandProperties, &pCmdProps) */
    hr = (**(int(__stdcall ***)(void *, void *, void **))pCmd)(
        pCmd, (void *)0x00a860e8, &pCmdProps);
    if (hr < 0) {
      /* FUN_0041d7b0 — Release if non-null */
      if (pCmdProps != 0) {
        (**(void(__stdcall ***)(void *))pCmdProps)[2](pCmdProps);
      }
      return hr;
    }

    /* ICommandProperties::SetProperties @ vtbl+0x10 */
    hr = (*(int(__stdcall **)(void *, int, void *))(*(int *)pCmdProps + 0x10))(
        pCmdProps, cSets, rgPropertySets);
    if (pCmdProps != 0) {
      (**(void(__stdcall ***)(void *))pCmdProps)[2](pCmdProps);
    }
    if (hr < 0) {
      return hr;
    }
  }

  if (pcRowsAffected == 0) {
    pcRowsAffected = scratch_rows;
  }

  pCmd = *(void **)((char *)ctx + 0x24);
  /* ICommand::Execute @ vtbl+0x10:
       (pUnkOuter=0, riid=IID_IRowset, pParams, pcRowsAffected, ppRowset) */
  hr = (*(int(__stdcall **)(void *, int, void *, void *, void *, void **))(
           *(int *)pCmd + 0x10))(
      pCmd,
      0,
      (void *)0x00a8608c,
      pParams,
      pcRowsAffected,
      ppRowset);

  if (hr >= 0) {
    pRowsetObj = *(void **)((char *)ctx + 0x10);
    if (pRowsetObj != 0) {
      /* QI IID_IRowsetChange → ctx+0x14; return ignored */
      (**(int(__stdcall ***)(void *, void *, void *))pRowsetObj)(
          pRowsetObj, (void *)0x00a860f8, (char *)ctx + 0x14);
    }
  }
  return hr;
}
