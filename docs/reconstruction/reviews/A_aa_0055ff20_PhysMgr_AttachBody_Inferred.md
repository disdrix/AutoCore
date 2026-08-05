# Review A (reconstruction fidelity): `aa_0055ff20` PhysMgr_AttachBody_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0055ff20` |
| **VA** | `0x0055ff20`–`0x00560017` |
| **Body** | **248 bytes** (`0xF8`) |
| **Canonical name** | `PhysMgr_AttachBody_Inferred` |
| **Ghidra name** | `FUN_0055ff20` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W29-R) |
| **Counterpart** | `reviews/B_aa_0055ff20_PhysMgr_AttachBody_Inferred.md` |
| **System** | phys / manager body attach |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` + `get_function_by_address` + callers/xrefs |
| **Verdict** | **accept** |

---

## 1. Purpose

Manager-side **attach** of a physics body:

1. `body[+8] = manager`.
2. LocalWorklist init from `*(mgr+0x234)`.
3. Body `vtbl+0x18` + mgr `[+0xc4] vtbl+4` collect new pairs (null-safe `body+0x1c`).
4. Serial `body[+0x20] = mgr[+0x130]++`.
5. If pairs: CanonAndSort; SortedDiffWalk(new, empty) with ECX=`*(mgr+0x138)`.
6. Short refcount `body+6` ++; push onto `mgr+0x120` vector (grow via `FUN_005b3370(...,4)` when count==cap&`0x7fffffff`).
7. `FUN_0062a4d0` notify; LocalWorklist_Release; return body.

Twin detach: `FUN_00560020` (W29-S).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0055ff20_FUN_0055ff20.md` (+ 2026-07-29 W29-R append) |
| Annotated | `docs/reconstruction/raw/aa_0055ff20_FUN_0055ff20.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/PhysMgr_AttachBody_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0055ff20.cpp` |
| Function record | `docs/reconstruction/functions/aa_0055ff20_FUN_0055ff20.md` |
| Named record | `docs/reconstruction/functions/aa_0055ff20_PhysMgr_AttachBody_Inferred.md` |
| Live | decompile ≡ raw CF; prologue frame+align; epilogue `8B C7 … C2 04 00` |
| Nested duals | W27-N Release/SortedDiffWalk; W28-Q CanonAndSort |

---

## 3. Signature (sealed)

```c
// thiscall; ECX = manager; stack body*; ret 4; returns body*
int * PhysMgr_AttachBody_Inferred(int manager /*ECX*/, int *body);
```

| Formal | Source | Conf |
|---|---|---|
| manager | ECX (`MOV ESI,ECX`) | **High** |
| body | `[EBP+8]` (`MOV EDI,[EBP+8]`) | **High** |
| return | EAX = EDI (body) | **High** |
| cleanup | `ret 4` | **High** |

---

## 4. Control flow (clean ≡ raw ≡ live)

```
body[2]=manager
LocalWorklist_Init(*(mgr+0x234))
body->vtbl+0x18; mgr[+0xc4]->vtbl+4(slot=body+0x1c)
body[8]=mgr[+0x130]++
if pair_count: CanonAndSort; SortedDiffWalk(left, n, empty, 0)
body.short[+6]++
if count==cap&0x7fffffff: grow vec stride 4
vec[count++]=body
FUN_0062a4d0(mgr, body)
LocalWorklist_Release
return body
```

| Stage | Match | Conf |
|---|---|---|
| Owner stamp + serial | **Yes** | **High** |
| Worklist + SortedDiffWalk attach | **Yes** | **High** |
| Vector grow mask | **Yes** | **High** |
| thiscall + ret 4 + return body | **Yes** | **High** |

---

## 5. Gaps / open

1. Product manager/body class English.
2. Full body layout beyond sealed offsets (+6, +8, +0x1c, +0x20).
3. Runtime / bit-exact.

**Verdict:** **accept**
