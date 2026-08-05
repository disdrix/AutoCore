# Review A (reconstruction fidelity): `aa_0055fbf0` WorldObj_UnbindLinks_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0055fbf0` |
| **VA** | `0x0055fbf0`–`0x0055fd72` |
| **Canonical name** | `WorldObj_UnbindLinks_Inferred` |
| **Ghidra name** | `FUN_0055fbf0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W26-D) |
| **Counterpart** | `reviews/B_aa_0055fbf0_WorldObj_UnbindLinks_Inferred.md` |
| **System** | world-object / manager unbind |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` + `analyze_function_complete`; callers |
| **Verdict** | **accept** |

---

## 1. Purpose

Manager **unbind / remove spatial-query links** for a world object:

1. `FUN_0062d960(*(manager+0x234))` preprocess.
2. If `*(obj+0xc)≠0` and query vcall on `*(manager+0xc4)+0xc` yields count>0:
   - `*(obj+0x40)==0` → simple `FUN_006297e0(0,0,out_a,count)`
   - else → complex `FUN_006caaa0` + per-hit `FUN_006297e0` / clear `+0x90` / optional free tag `0x12`
3. Always `FUN_0055f4c0` (stack alloc cleanup) before return.

Used as step 1 of rebind (`00560e90`) and in remove/defer unbind chains.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0055fbf0_FUN_0055fbf0.md` (+ 2026-07-29 W26-D append) |
| Annotated | `docs/reconstruction/raw/aa_0055fbf0_FUN_0055fbf0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/WorldObj_UnbindLinks_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0055fbf0.cpp` |
| Function record | `docs/reconstruction/functions/aa_0055fbf0_FUN_0055fbf0.md` |
| Named record | `docs/reconstruction/functions/aa_0055fbf0_WorldObj_UnbindLinks_Inferred.md` |
| Live | decompile ≡ raw; `read_memory` 386 B; dual `C2 04 00` epilogues |
| Prior dual | W24-B `WorldObj_RebindActivate_Inferred` (unbind→bind order) |

---

## 3. Signature (sealed)

```c
// thiscall; 1 stack formal; ret 4; void
void WorldObj_UnbindLinks_Inferred(void *manager /*ECX*/, void *obj /*stack*/);
```

| Formal | Source | Conf |
|---|---|---|
| manager | ECX | **High** |
| obj | Stack[0x4] | **High** |
| return | void (no EAX contract) | **High** |
| cleanup | `ret 4` both exits | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
FUN_0062d960(*(mgr+0x234))
if *(obj+0xc)!=0 and query_vcall(...) with count>0:
  if *(obj+0x40)==0:
    FUN_006297e0(0,0,out_a,count)
  else:
    install stack callback on *(mgr+0x138)+0x24
    FUN_006caaa0(...); restore slot
    for hits: FUN_006297e0 + zero +0x90
    maybe free tag 0x12
FUN_0055f4c0(); return
```

| Stage | Match | Conf |
|---|---|---|
| Entry preprocess | **Yes** | **High** |
| Query gate + count | **Yes** | **High** |
| Simple vs complex on `obj+0x40` | **Yes** | **High** |
| Always `FUN_0055f4c0` | **Yes** | **High** |
| ret 4 thiscall | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

Body **386 B**; exclusive end `0x0055fd72`. Both logical exits: `5F 5E 5D 83 C4 38 C2 04 00`.

Frame: `SUB ESP,0x38`; ESI=manager (ECX); EBP=obj (from `[esp+0x48]` after pushes).

---

## 6. Gaps

- Product English for manager / query iface at `manager+0xc4`.
- Nested callee contracts (`0062d960`, `006297e0`, `006caaa0`, `0055f4c0`) — not OWN.
- Bind twin `0055fa40` — W26-E.
- Decompiler unreachable block / possible `FUN_005b3300` growth — residual Medium.
- Runtime / bit-exact — open.

---

## 7. Verdict

CF, ABI, unbind role vs callers, and dual-path structure sealed. Nested product contracts residual. Naming **INFERRED** from role. → **accept**.
