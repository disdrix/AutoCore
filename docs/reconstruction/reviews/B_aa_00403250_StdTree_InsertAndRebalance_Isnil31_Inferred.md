# Review B (skeptical / independent): `aa_00403250` StdTree_InsertAndRebalance_Isnil31_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00403250` |
| **VA** | `0x00403250` |
| **Canonical name** | `StdTree_InsertAndRebalance_Isnil31_Inferred` |
| **Review date** | `2026-08-05` (MEGA-047) |
| **Reviewer role** | Skeptical naming / anti-overclaim |
| **Counterpart** | `reviews/A_aa_00403250_StdTree_InsertAndRebalance_Isnil31_Inferred.md` |
| **System** | STL / map-set |
| **Verdict** | **accept-with-gaps** — agree with A |

---

## 1. Adversarial read of proposed names

| Candidate | Ruling |
|---|---|
| `FUN_00403250` only | Acceptable scaffold; under-describes sealed role |
| `Named_CalleeOf_*NotifyActiveMissionChanged_00403250` | **Reject** — chain-of-caller; shared STL helper |
| `Mission_InsertActiveNode` | **Reject** — no mission-domain string; parent is generic int-key map |
| `StdTree_InsertAndRebalance_Isnil29_*` | **Reject** — wrong family (color@+0x28 / node 0x30 / RET 0x10 thiscall-map) |
| `StdTree_InsertAndRebalance_Isnil21_*` | **Reject** — wrong family (color@+0x20 / node 0x28) |
| `StdTree_EraseAndRebalance_Isnil31_*` | **Reject** — this is insert path (buynode + size++); erase is `00408ed0` |
| `StdTree_InsertAndRebalance_Isnil31_Inferred` | **Accept** — family-aligned; `_Inferred` honest |

---

## 2. Attacks on A's CF / ABI claims

| Attack | Result |
|---|---|
| Function is insert-or-find (compares keys) | **Fails** — no key compare; parent `00402b30` compares `node[4]` / `*EBX` |
| Map lives in ECX (standard thiscall-map like isnil29) | **Fails** — entry `mov esi,ecx` (where); EDI used as map without `mov edi,ecx`; parent `MOV EDI,EAX` keeps map in EDI across call |
| RET 0x10 (four stack args) | **Fails** — epilogue `C2 0C 00`; call sites push **3** args |
| isnil@+0x29 / color@+0x28 | **Fails** — color immediates `+0x30`; parent isnil walk `+0x31`; buynode `operator_new(0x38)` |
| Max size same as isnil29 (`0x0AAAAAA8`) | **Fails** — imm `0x7fffffe` matches ~0x20 value stride |
| Lrotate/Rrotate thiscall ECX=map | **Fails** — sites `PUSH EDI` (map) + ECX=node (matches dualed Lrot isnil31 ABI) |
| Product English proven | **Fails** — open; keep `_Inferred` |
| Mission-specific semantics | **Fails** — only chain nesting; body is pure STL insert |

---

## 3. Agreement with Review A

- Always-insert + RB + ABI + family layout: **agree Confirmed/High**
- Name with `_Inferred`: **agree**
- Gaps (PDB, payload English, residual peers, runtime): **agree open**
- Retire Named_CalleeOf scaffold: **agree**

---

## 4. Residual risks

- Do not merge with isnil29/isnil21 insert clones without layout + ABI check (this unit's EDI=map / ECX=where form is distinct).
- Buynode `FUN_00403f30` / ctor `FUN_00404360` remain undualed OWN residuals (MEGA-048 nest).
- Parent `FUN_00402b30` undualed (MEGA-040) — insert-or-find wrapper residual.
- Rrotate twin `00403ee0` residual (shared with erase path).

**Verdict:** **accept-with-gaps**
