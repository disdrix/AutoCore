# Annotated low-level: MissionDialog_SetNpcObjectAndNameCaption_Inferred

| Field | Value |
|---|---|
| Stable ID | `aa_008aa4b0` |
| VA | `0x008aa4b0`–`0x008aa50e` inclusive (**95 B** / `0x5F`) |
| Ghidra | `FUN_008aa4b0` |
| Canonical | `MissionDialog_SetNpcObjectAndNameCaption_Inferred` |
| System | `missions-progression` |
| Date | 2026-08-05 (MEGA-058 OWN dual refresh) |
| Prior scaffold | `Named_CalleeOf_Client_ShowNpcMissionDialogUI_008aa4b0` (**retired**) |

**Tools:** live Ghidra decompile + disassemble_function + read_memory + callers/xrefs + parent framing. **No** `disassemble_bytes`. No Launcher.

---

## Purpose

Mission-dialog helper that **stamps the NPC object** and **binds or clears the NPC-name caption widget** before thr/steer/handbrake park (and on ShowNpc present paths):

1. `dialog+0x644 ← EAX` (NPC object*; 0 = none).
2. If caption widget at `dialog+0x6d8` is non-null:
   - NPC null → SetText empty C-string `DAT_00a1419b` via **vtbl+0x1d8**(cstr,1,1).
   - NPC non-null → resolve display name via secondary object vtbl **+0x160**(1,1), then **vtbl+0x1d8**(name) one-arg.
   - Tail-jump **vtbl+0x34c** refresh.

Sibling chrome: `Client_MissionDialog_SetHeaderCaption_Inferred` (`0x008aaf60`) uses **`+0x6e0`** with the same **+0x1d8 / +0x34c** paint pair for the *header* caption — this unit is the **NPC name** bank at **`+0x6d8`** plus the **`+0x644`** object stamp.

---

## ABI (register contract)

| Formal | Location | Role |
|---|---|---|
| dialog host | **ESI** | mission dialog UI* (`*(client+0x1058)` or EBX in ShowNpc) |
| NPC object | **EAX** | object* or **0** to clear name + stamp null |
| return | none | plain **`RET`** (`C3`) |
| stack | none | no formals; no `RET n` |

Callers must set ESI/EAX before CALL. Not thiscall (ECX is not the dialog at entry — body loads ECX from `[ESI+0x6d8]`).

---

## Pseudocode (annotated ≡ live)

```c
// ESI = dialog*, EAX = npcObject* (0 clear)
// plain RET
void MissionDialog_SetNpcObjectAndNameCaption_Inferred(void)
{
  int *nameWidget;   // dialog+0x6d8
  int npc;           // in EAX
  int *widgetVtbl;
  undefined4 nameStr;
  int dialog;        // unaff ESI

  nameWidget = *(int **)(dialog + 0x6d8);
  *(int *)(dialog + 0x644) = npc;          // always stamp NPC object
  if (nameWidget == (int *)0x0) {
    return;
  }
  if (npc == 0) {
    // clear: three-arg SetText(empty, 1, 1)
    (**(code **)(*nameWidget + 0x1d8))(&DAT_00a1419b /* "" */, 1, 1);
  }
  else {
    // bind: secondary vtbl GetDisplayName-like, then one-arg SetText(name)
    //   secondary = *(*(npc+4)+4); this = secondary + npc + 4  (LEA)
    widgetVtbl = (int *)*nameWidget;       // saved in EDI across GetName
    nameStr = (**(code **)(*(int *)(*(int *)(*(int *)(npc + 4) + 4) + 4 + npc) + 0x160))(1, 1);
    (**(code **)((int)widgetVtbl + 0x1d8))(nameStr);
  }
  // tail JMP (not CALL) — decompiler "jumptable" warning is false positive
  (**(code **)(**(int **)(dialog + 0x6d8) + 0x34c))();
  return;
}
```

---

## Control flow

| Stage | Bytes / notes |
|---|---|
| Load widget `+0x6d8` | `8B 8E D8 06 00 00` |
| Stamp `+0x644 ← EAX` | `89 86 44 06 00 00` (before null-widget check completes — store always) |
| Widget null → RET | `85 C9` / `74 4E` |
| NPC null → clear branch | `85 C0` / `74 2B` |
| Bind: GetName `+0x160`(1,1) | `6A 01 6A 01` + `FF 92 60 01 00 00` |
| Bind: SetText one-arg | `50` + `FF 97 D8 01 00 00` |
| Clear: SetText three-arg empty | `6A 01 6A 01 68 9B 41 A1 00` + `FF 90 D8 01 00 00` |
| Refresh tail JMP `+0x34c` | `FF A2 4C 03 00 00` |
| RET | `C3` |

---

## Callers

| Parent | Site | Role |
|---|---|---|
| `Client_ShowNpcMissionDialogUI` | `0x0094397d`, `0x00943a75` | stamp NPC + name before journal/present finalize |
| `FUN_009373e0` | `0x00937411` | dialog helper **before** thr0 / steer0 / HB park |

---

## Open questions

1. Product/PDB English for function and widget class at `+0x6d8`.
2. Product name for vtbl `+0x160` / `+0x1d8` / `+0x34c`.
3. Exact type of GetName return (C-string vs string object*).
4. Why clear path uses 3-arg SetText and bind path uses 1-arg (same slot) — preserved as-is.
5. Runtime / bit-exact / differential (terminal false).
