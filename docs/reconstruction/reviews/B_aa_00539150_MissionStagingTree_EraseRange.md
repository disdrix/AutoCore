# Review B (skeptical / adversarial): `aa_00539150` MissionStagingTree_EraseRange

| Field | Value |
|---|---|
| **Stable ID** | `aa_00539150` |
| **VA** | `0x00539150` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00539150_MissionStagingTree_EraseRange.md` |
| **System** | `missions-progression` |
| **Dual status** | **Present** (W24-L) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Single-node erase only | **Falsified** — full-clear arm + loop over range |
| 2 | Hash-table remove (`CNDHash_*`) | **Falsified** — RB tree; callees DestroySubtree/EraseNode |
| 3 | `ret 4` / free-function cdecl | **Falsified** — epilogue `ret 0xc`; ECX=this |
| 4 | Always bulk-destroys without rebalance path | **Falsified** — selective path uses EraseNode (RB rebalance) |
| 5 | Clears active-objective hash `+0x548` | **Falsified** — staging map only (`+0x508` at dtor site) |
| 6 | Dead / unreferenced | **Falsified** — xrefs `0053ae82`, `0052f607` |
| 7 | Bit-exact / runtime proven | **Fail** — static only |

---

## 2. Decisive evidence

- Live decompile ≡ raw 2026-07-23 spine (two-arm erase).
- Entry/epilogue `read_memory` seals three stack args + `ret 0xc`.
- Peer duals: `MissionStagingTree_DestroySubtree` (`00537ef0`), `EraseNode` (`00538780`).
- `FUN_0053ae70` is classic map dtor: erase-all then `operator_delete(header)`.
- Char dtor site: `LEA EDI,[ESI-0x898]` with adj-this `+0xda0` → map base `+0x508`.

---

## 3. Port risk

| Risk | If wrong |
|---|---|
| Port only full-clear arm | Selective erase leaks / leaves stale nodes |
| Treat as hash remove | Wrong container; corrupt missions |
| Wrong `ret` width | Stack smash on callers |
| Skip successor before EraseNode | Use-after-free / infinite loop |

**Verdict:** Accept as staging-map **range erase**. Do not collapse into `CNDHash_Remove` or single-node-only API.
