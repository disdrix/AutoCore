# Review A (reconstruction fidelity): `aa_004da630` CVOGCombat_OnDeathAwardKillXp

| Field | Value |
|---|---|
| **Stable ID** | `aa_004da630` |
| **VA** | `0x004da630` |
| **Canonical name** | `CVOGCombat_OnDeathAwardKillXp` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004da630_CVOGCombat_OnDeathAwardKillXp.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGCombat_OnDeathAwardKillXp.cpp` |
| Callee | `CVOGCombat_CalculateAndAwardKillXP` raw/clean |
| Prior art | `docs/XP.md` § Kill XP entry / convoy |

---

## 2. Signature

| Element | Raw | Clean | Match |
|---|---|---|---|
| `__thiscall` 3 args | `param_1, param_2*, param_3*` | Renamed lootCtx / killer / victim | **Yes** |
| Returns `void*` | Present (SEH/loot leftovers) | Present | **Yes** |
| Early null killer | `param_2==0` | Same | **Yes** |

---

## 3. Control-flow phases (clean ≡ raw)

| Phase | Present in raw | Present in clean | Match |
|---|---|---|---|
| Resolve killer via `+0x210` | Yes | Yes | **Yes** |
| Lazy loot singleton `DAT_00b037e8` | Yes | Yes | **Yes** |
| Victim position snapshot | Yes | Yes | **Yes** |
| Assist bookkeeping mode `+0xac==3` | Yes | Yes | **Yes** |
| Type `0xe` vehicle / `0x12` creature | Yes | Yes (named enums) | **Yes** |
| Solo award `count=0` | Yes | Yes | **Yes** |
| Convoy loop 4 + range `DAT_00aaa8a8` | Yes | Yes | **Yes** |
| TFID list path `count=4` | Yes | Yes | **Yes** |
| Mult `*(float*)(template+0x500)*local_74*share` | Yes | Yes | **Yes** |
| Credits when level delta `< 0xb` | Yes | Yes | **Yes** |
| Loot rolls + special CBID drop | Yes | Yes | **Yes** |
| Flag `+0xf6` skip credits/loot | Yes | Yes | **Yes** |

---

## 4. State mutations

| Area | Effect |
|---|---|
| Kill XP | `CalculateAndAwardKillXP` per recipient |
| Assist tags | `FUN_004d31a0` |
| Credits floaters | `FUN_004d2750` / `FUN_0050ac80` / `FUN_004d4440` |
| Loot objects | `FUN_004d2820`, `GiveItemByCbid` |
| SEH `ExceptionList` | Frame install/restore |

---

## 5. Gaps

1. Many `FUN_*` callees still unnamed (convoy lock/unlock, credit math).
2. Decompiler `SQRT` vs clean `sqrtf` — same math intent; not bit-proven.
3. `unaff_EDI` sixth arg to award still residual.
4. Ghidra “unreachable block 0x004dad5f” not reconstructed (intentionally omitted).

**Verdict:** Phase structure and award call sites match raw. **accept-with-gaps.**
