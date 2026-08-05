# Raw capture: FUN_008ac7a0

| Field | Value |
|---|---|
| **Stable ID** | `aa_008ac7a0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x008ac7a0` |
| **Body** | `0x008ac7a0`–`0x008ac884` (228 B / `0xE4`) |
| **Canonical name** | `FUN_008ac7a0` |
| **Inferred name** | `Client_MaybeShowMultiActiveMissionTip_Inferred` |
| **System** | `missions-progression` |
| **Capture timestamp** | `2026-07-23` (scaffold); live seal append `2026-08-04` WQ7R-A |
| **Tool** | Ghidra MCP `decompile_function` + `analyze_function_complete` + `read_memory` + callers/xrefs |
| **Integrity** | Do not overwrite the original raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile — 2026-07-23; reconfirmed live 2026-08-04)

```c
void FUN_008ac7a0(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if ((DAT_00d1b6d8 != 0) && ((*(byte *)(DAT_00d1b6d8 + 0xd34) & 1) == 0)) {
    iVar1 = *(int *)(DAT_00d1b6d8 + 0x540);
    iVar2 = 0;
    iVar3 = 0;
    if (*(char *)(iVar1 + 0x1d) != '\0') {
      FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");
      FUN_007a4480(0,"VOG_DEBUG_STOP");
    }
    *(undefined1 *)(iVar1 + 0x1d) = 1;
    while( true ) {
      iVar1 = *(int *)(DAT_00d1b6d8 + 0x540);
      if (*(char *)(iVar1 + 0x1d) == '\0') {
        FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");
        FUN_007a4480(0,"VOG_DEBUG_STOP");
      }
      if (iVar3 == 0) {
        iVar3 = *(int *)(iVar1 + 0x14);
      }
      else {
        iVar3 = *(int *)(iVar3 + 0x14);
      }
      if (iVar3 == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = *(int *)(iVar3 + 8);
      }
      if (iVar1 == 0) break;
      if ((*(short *)(iVar1 + 0xf8) == 0) && (*(int *)(iVar1 + 0xfc) != -1)) {
        iVar2 = iVar2 + 1;
      }
    }
    *(undefined1 *)(*(int *)(DAT_00d1b6d8 + 0x540) + 0x1d) = 0;
    if (1 < iVar2) {
      Client_MaybeShowFirstTimeTip(0x20);
    }
  }
  return;
}
```

---

## Live seal append — 2026-08-04 (WQ7R-A)

### Tools
- `decompile_function` @ `0x008ac7a0` — body **≡** 2026-07-23 raw CF
- `analyze_function_complete` — classification worker; callers/callees
- `get_function_by_address` — body `008ac7a0`–`008ac884`
- `get_function_callers` / `get_function_xrefs` — sole call site
- `read_memory` 240 B @ entry (hex below)
- **No** `disassemble_bytes`; **no** Launcher

### ABI (bytes)
- No stack formals; prologue uses `push ecx` only as local/stack slot for gate byte
- Epilogue: plain **`C3`** (cdecl-style no-arg `ret`)
- Tip call is **thiscall**: `MOV ECX, 0x00d1a840` / `PUSH 0x20` / `CALL Client_MaybeShowFirstTimeTip` / `POP ECX`
- Return: void (no EAX contract observed)

### Entry hex (`read_memory` 240 B @ `0x008ac7a0`)
```
51a1d8b6d10085c00f84d50000008a88340d000080e101884c24030f85c20000005356578bb84005000033db33f6807f1d00741968d07ca20056e8a17cefff684458a10056e8967cefff83c410c6471d01eb0d8da424000000008d9b000000008b15d8b6d1008bba40050000807f1d00751b689c7ca2006a00e8627cefff684458a1006a00e8567cefff83c41085f674058b7614eb038b771485f674058b4608eb0233c085c074186683b8f80000000075ae83b8fc000000ff74a583c301eba0a1d8b6d1008b88400500005f5e83fb02c6411d005b7c0c6a20b940a8d100e8dd4ef5ff59c3
```

### Callers / callees
| Kind | Symbol | VA / note |
|------|--------|-----------|
| Caller (sole) | `Client_MissionDialogHandleButton` | call @ `0x008aec20` (accept-offer path after `GiveMission` / hide / tip `2`) |
| Callee | `FUN_007a4480` | debug log (HashError / VOG_DEBUG_STOP) |
| Callee | `Client_MaybeShowFirstTimeTip` | tip id **`0x20`**, this=`DAT_00d1a840` |

### Gate / walk (sealed CF)
1. Require `DAT_00d1b6d8 != 0` and `( *(byte*)(DAT_00d1b6d8 + 0xd34) & 1 ) == 0`
2. Hash root `*(DAT_00d1b6d8 + 0x540)`; set traversal lock `hash+0x1d = 1` (log if already locked)
3. Linked walk: first node `hash+0x14`, next `node+0x14`; payload `node+8`
4. Count when `*(short*)(payload+0xf8)==0` **and** `*(int*)(payload+0xfc)!=-1`
5. Clear lock `hash+0x1d = 0`
6. If count **≥ 2** (`cmp ebx,2` / `jl skip`): `Client_MaybeShowFirstTimeTip(0x20)`

### Terminal
`terminal_coverage = false` (no Launcher / runtime Confirmed).
