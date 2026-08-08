# Review A (reconstruction fidelity): `aa_0040c6b0` CNDHash_TraverseToNext_TFID_Node0x28_RegEdiEsi_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040c6b0` |
| **VA** | `0x0040c6b0`–`0x0040c6f0` (**65** bytes incl. dual `RET`; pad `CC`) |
| **Canonical name** | `CNDHash_TraverseToNext_TFID_Node0x28_RegEdiEsi_Inferred` |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_0040c6b0_CNDHash_TraverseToNext_TFID_Node0x28_RegEdiEsi_Inferred.md` |
| **System** | interaction-activation / CNDHash |
| **Live tools** | Ghidra `decompile_function`, `force_decompile`, `analyze_function_complete`, `get_function_callers`, `get_function_xrefs`, `get_xrefs_to`, `get_function_callees`, `get_function_by_address`, `disassemble_function`, `read_memory`; parent disasm of `Client_UpdateNpcInteractIcons`. **No** `disassemble_bytes`. **No** Launcher. |
| **Work item** | MEGA-112 OWN-ONLY dual |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose (behavioral)

**CNDHash ordered-list iterator step** under an already-held traversal lock, for the **0x28 / u64-key node family**:

1. If `*(hash+0x1d) == 0` → log `"HashError:TraverseToNext, not locked for traversal"` + `"VOG_DEBUG_STOP"` (continues; does **not** return early).
2. Cursor `*pCursor`:
   - If **0** → seed from list head `*(hash+0x14)`; write cursor.
   - Else → advance `cursor = *(cursor+0x20)`.
3. If cursor node non-null → return **payload** `*(node+0xc)`.
4. Else → return **0**.

Does **not** mutate membership, lock byte, or freelist. Sole live consumer: `Client_UpdateNpcInteractIcons` walking the npc-interact hash at `*[DAT_00d1b644+0xe8f4]`, typing payload as **TFID_16\*** then `Object_ResolveFromTFID`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Fresh decompile Pass A | Ghidra `decompile_function` @ `0x0040c6b0` |
| Force re-decompile Pass B | Ghidra `force_decompile` @ `0x0040c6b0` (**identical**) |
| Complete analysis | `analyze_function_complete` (xrefs/callers/callees/disasm/vars) |
| Machine | `disassemble_function` + `read_memory` 96 B @ entry |
| Function range | entry `0040c6b0`, body `0040c6b0`–`0040c6f0` |
| Callers | `Client_UpdateNpcInteractIcons` `0x0091b8d0` ×2 (`0091b961`, `0091be26`) |
| Parent ABI seal | disasm: `MOV EDI,[…+0xe8f4]`; `LEA ESI,[esp+…]`; `CALL 0040c6b0` |
| Raw / annotated / clean | `raw/aa_0040c6b0_*`, `reconstructed-exact/CNDHash_TraverseToNext_TFID_Node0x28_RegEdiEsi_Inferred.cpp` |
| Function records | `functions/aa_0040c6b0_FUN_*` + named |

---

## 3. Authoritative body (Ghidra dual A/B 2026-08-05)

**Pass A** ≡ **Pass B**:

```c
undefined4 FUN_0040c6b0(void)
{
  int iVar1;
  int *unaff_ESI;
  int unaff_EDI;

  if (*(char *)(unaff_EDI + 0x1d) == '\0') {
    FUN_007a4480(0, "HashError:TraverseToNext, not locked for traversal");
    FUN_007a4480(0, "VOG_DEBUG_STOP");
  }
  if (*unaff_ESI == 0) {
    *unaff_ESI = *(int *)(unaff_EDI + 0x14);
    iVar1 = *(int *)(unaff_EDI + 0x14);
  }
  else {
    iVar1 = *(int *)(*unaff_ESI + 0x20);
    *unaff_ESI = iVar1;
  }
  if (iVar1 != 0) {
    return *(undefined4 *)(iVar1 + 0xc);
  }
  return 0;
}
```

---

## 4. Machine seal

Hex start: `807f1d00751b689c7ca200…` ends `…8b400cc3 33c0c3 cc…`.

| Claim | Evidence | Conf |
|---|---|---|
| **EDI** = hash; **ESI** = cursor\*\*; plain **`RET`** | `CMP [EDI+0x1d]`; `MOV EAX,[ESI]`; dual `c3`; parent `MOV EDI`/`LEA ESI`/`CALL` | **High** |
| Lock check `hash+0x1d` | `cmp byte [edi+0x1d],0` | **High** |
| Head seed `hash+0x14` | `mov eax,[edi+0x14]` | **High** |
| Advance via `node+0x20` | `mov eax,[eax+0x20]` | **High** |
| Return payload `node+0xc` | `mov eax,[eax+0xc]` | **High** |
| Non-fatal unlocked log | fall-through after two `FUN_007a4480` | **High** |
| Dual A/B decompile identity | force ≡ non-force | **High** |
| Sole caller npc-interact path | 2 xrefs both in `Client_UpdateNpcInteractIcons` | **High** |
| Payload is TFID\* | parent cast + `Object_ResolveFromTFID` | **High** (consumer-local) |

---

## 5. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Lock==0 → dual log → fall-through | **Yes** |
| cursor==0 → head seed +0x14 | **Yes** |
| else advance +0x20 | **Yes** |
| node≠0 → return +0xc else 0 | **Yes** |
| No lock write / no free / no thiscall | **Yes** |

---

## 6. Confidence

| Claim | Level |
|---|---|
| CF sealed dual A≡B ≡ raw ≡ machine | **High** |
| Product role TraverseToNext | **High** (string) |
| Requires lock set by caller (logs if not) | **High** |
| Returns value ptr, not node | **High** |
| Node family ≠ skill 0x1c twin `00411900` | **High** |
| Product hash RTTI / stamp at `e8f4` | **Open** → `_Inferred` |
| Runtime / bit-exact | **Open** |

**Verdict:** **accept-with-gaps.**

### Gaps

1. Product English / RTTI for hash @ `DAT_00d1b644+0xe8f4`.
2. Whether payload type is TFID\* in every hypothetical future consumer (currently only one).
3. Runtime / bit-exact / differential.
