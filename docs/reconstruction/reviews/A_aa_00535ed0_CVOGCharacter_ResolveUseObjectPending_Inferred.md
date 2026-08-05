# Review A (reconstruction fidelity): `aa_00535ed0` CVOGCharacter_ResolveUseObjectPending_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00535ed0` |
| **VA** | `0x00535ed0`–`0x0053607e` |
| **Canonical name (proposed)** | `CVOGCharacter_ResolveUseObjectPending_Inferred` |
| **Ghidra name** | `FUN_00535ed0` |
| **Prior aliases** | `Named_CalleeOf_Named_CalleeOf_CVOGReaction_RecordFirstTimeEvent_00535ed0` (scaffold only) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (Path A) |
| **Counterpart** | `reviews/B_aa_00535ed0_CVOGCharacter_ResolveUseObjectPending_Inferred.md` |
| **System tag** | `missions-progression` |
| **Agent** | W25-A OWN-ONLY |
| **Verdict** | **accept** on CF / kind10 / UI0x14 / TFID-null / ABI; **accept-with-gaps** on product English + secondary-object type |

**Tools:** Ghidra `decompile_function` + `read_memory` + `get_function_by_address` + `get_function_xrefs` + `get_function_callees`. No `disassemble_bytes`. No Launcher. No parent ledger edits.

---

## 1. Purpose

Character-side **pending use-object** resolver: given commit flag, either cancel/commit secondary object, send logic-UI packet **0x14**, or `EvaluatePendingObjectives` **kind 10** after TFID resolve — then clear pending slots.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Live Ghidra decompile | `FUN_00535ed0` @ `0x00535ed0` (≡ raw CF) |
| Body | `0x00535ed0`–`0x0053607e` |
| Prologue | `sub esp,0x144`; `mov esi,ecx` |
| Epilogue | `add esp,0x144; ret 4` |
| Null TFID | `DAT_009cee98` = `ffffffffffffffff0000000000000000` |
| Callers | `005360f0`, `0060b410`, `0060b440`, `00515520` |
| Sibling | `FUN_00535c60` kind **9** (W24-K sealed; not owned) |
| Kind owner | `CVOGCharacter_EvaluatePendingObjectives` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body end `0x0053607e` | **High** | `get_function_by_address` |
| `__thiscall` + `ret 4` | **High** | `C2 04 00` |
| ECX=character | **High** | offsets `+0xc7c…+0xca0` |
| Gate `vbase \|\| !+0xc7c` | **High** | prologue bytes |
| Kind **10** EvaluatePending | **High** | decompile call |
| UI kind **0x14** | **High** | `local_11c = 0x14` |
| Null TFID seed all-ones | **High** | `read_memory` |
| Live ≡ raw CF | **High** | re-decompile 2026-07-29 |
| Secondary type / vtbl+0x2cc name | **Tentative** | structural only |
| Product English | **Probable** | `_Inferred` |

---

## 4. Sealed control flow

```
ResolveUseObjectPending(char, commit) -> bool
  if !vbase || !flag(+0xc7c): clear flag; return false
  ok = true
  if tfid_slot_invalid(+0xc88..):
    if p=*(+0xc9c):
      if commit: p.vtbl+0x2cc(1,char); clear p/aux; goto FINISH
      if flag(+0xc7d): p.vtbl+0x2cc(0,char); clear; goto FINISH
  else:
    if !commit:
      if !flag(+0xc7d): return false
      SendLogicUiPacket(kind=0x14); goto FINISH
    obj = ResolveFromTFID(+0xc88)
    if obj: EvaluatePending(char, 10, (float)cbid, 0, 0); goto FINISH
  ok = false
FINISH: clear flags/TFID/aux/timer; return ok
```

---

## 5. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Vbase / flag gate | **Yes** |
| Invalid-TFID secondary path | **Yes** |
| Valid-TFID UI 0x14 path | **Yes** |
| Kind 10 EvaluatePending | **Yes** |
| Finish nulling | **Yes** |
| Invented static callers | **None** — four CODE xrefs listed |

---

## 6. Gaps / open questions

1. Product enum names for kind `10` and UI `0x14`.
2. Type behind `char+0xc9c` and exact semantics of vtbl `+0x2cc` args.
3. Whether `FUN_0060b410` this-adjust is always the `+0xca0` object (not owned).
4. Runtime / bit-diff.

**Verdict:** CF spine **accept High**. **accept-with-gaps** for product naming + secondary type.
