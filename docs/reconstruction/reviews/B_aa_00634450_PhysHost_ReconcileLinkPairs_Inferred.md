# Review B (skeptical / adversarial): `aa_00634450` PhysHost_ReconcileLinkPairs_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00634450` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W29-R) |
| **Counterpart** | `reviews/A_aa_00634450_PhysHost_ReconcileLinkPairs_Inferred.md` |
| **Scratch** | `tmp/a_00634450.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is WorldObj_BindLinks | **Falsified** — BindLinks is `0055fa40`; this is host-side dual-list reconcile after pose write |
| 2 | Same as Phys_CommitPairListStorage | **Falsified** — that is `006297e0` (simple path); this always uses SortedDiffWalk path when lists non-empty |
| 3 | No stack formals / plain ret | **Falsified** — epilogue `C2 04 00` |
| 4 | Single worklist | **Falsified** — dual init + dual release (bytes: two `0062d960`, two `0055f4c0`) |
| 5 | Decompiler `uVar2=1` is second count | **Overstated residual** — `1` is vcall flag; second-list count is stack out (clean documents) |
| 6 | SortedDiffWalk this = d0+8 | **Falsified** — machine `MOV ECX,[mgr+0x138]`; d0+8 is stack formal |
| 7 | Product host name is retail | **Overstated** — `_Inferred` structural name only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Reconcile role / dual worklist | **High** | Wrong port of pose-update path |
| thiscall + ret 4 | **High** | ABI break |
| SortedDiffWalk ECX 0x138 | **High** | Wrong handler table |
| Second-list variable mapping | **Medium** | Naming of outs only; call order sealed |
| Product type English | **Medium** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes

```
SUB ESP,0x2C; PUSH ESI; MOV ESI,ECX
CMP [ESI+8],0; JE done
CALL FUN_0062d960 ×2 (mgr+0x238)
null-this slot host+0x1c; CALL [vtbl+0x14] flag=1
if lists: CanonAndSort×2; SortedDiffWalk; FUN_005fff20 (host+0x3c)
FUN_0055f4c0 ×2; POP ESI; ADD ESP,0x2C; RET 4
```

Live decompile 2026-07-29 ≡ raw 2026-07-23 CF. Residuals documented in clean/annotated.

---

## 4. Surviving contract for AutoCore

```
// After host pose/AABB write when manager present:
PhysHost_ReconcileLinkPairs_Inferred(host, query_param);
// Must preserve: dual worklist, vtbl+0x14 flag 1, SortedDiffWalk this=*(mgr+0x138),
// dual release, ret 4. Do not substitute BindLinks (0055fa40) or CommitPairList (006297e0).
```

---

## 5. Verdict

Adversarial pass **confirms** A: CF/ABI/role sealed; decompiler residuals called out → **accept**.
