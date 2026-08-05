# Review B (skeptical / adversarial): `aa_00537ef0` MissionStagingTree_DestroySubtree

| Field | Value |
|---|---|
| **Stable ID** | `aa_00537ef0` |
| **VA** | `0x00537ef0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00537ef0_MissionStagingTree_DestroySubtree.md` |
| **System** | `missions-progression` |
| **Dual status** | **Present** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Decompiler single free is complete CF | **Understated** — asm walks `*node` chain after each delete |
| 2 | Clears mission active hash `+0x540` | **Falsified** — only tree nodes; no hash touch |
| 3 | is-nil at `+0x48` (color only) | **Falsified** — gate is **`+0x49`** (nil byte) |
| 4 | No callers from mission grant path | **Falsified** — `FUN_0052d8b0` (GiveMission notify) calls @ `0x0052d9f6` |
| 5 | Safe to call on nil header without check | **Falsified** — nil short-circuits before free |
| 6 | Product name proven | **Unproven** |

---

## 2. Decisive evidence

- Xrefs: `FUN_0052d8b0`, `FUN_00539150` (range erase uses this for bulk root wipe), self-recursion.
- GiveMission path: grant → `FUN_0052d8b0(char,0,*def)` → may destroy staging nodes via this helper.
- Nil test `80 7f 49 00` sealed in image bytes.

---

## 3. Residual risks

| Risk | Level |
|---|---|
| Wrong child offset when porting free | **High** impact if +8 wrong |
| Double-free if called with non-tree pointer | Caller contract only |
| ABI ECX vs pure stack | **Low** for this unit if stack node correct |

**Verdict:** Accept destroy role; demand asm walk (not thin decompile) for ports.
