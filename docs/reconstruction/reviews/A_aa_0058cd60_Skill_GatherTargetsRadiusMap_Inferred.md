# Review A (reconstruction fidelity): `aa_0058cd60` Skill_GatherTargetsRadiusMap_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0058cd60` |
| **VA** | `0x0058cd60` |
| **Canonical name** | `Skill_GatherTargetsRadiusMap_Inferred` (was `FUN_0058cd60`) |
| **Ghidra symbol** | `FUN_0058cd60` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — live Ghidra) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0058cd60_Skill_GatherTargetsRadiusMap_Inferred.md` |
| **System** | skills-abilities / client interact pick |
| **Dual status** | **Present** |
| **Verdict** | **accept-with-gaps** — gather+filter+distance-map CF sealed; full mode catalog residual |

---

## 1. Purpose

**Area target gather** sibling of `Skill_GatherTargetsInArea` (`0x0058d330`):

1. Snapshot origin pose from `param_5` (xyzw).
2. Build empty **float-key map** head via `FUN_0058d9c0` (nil node self-links, size 0).
3. Iterate world object list from sector (`param_3+0xe4e8` → +0x20 head).
4. Per-object filters:
   - skip null / self (`param_4`)
   - vtbl+0x198 gate
   - TFID mismatch vs `param_1` (object id triple)
   - optional `FUN_005134e0` unless `param_10`
   - flag bit at `obj+0x17c` (`[0x5f]>>2 & 1`) must be clear
5. Type branch: type **0x0e** vehicles need RTTI vehicle + seat/owner TFID checks; else `FUN_005130e0(1)`.
6. Mode filter `param_8`: hostile/ally/living/etc. (cases 0,1,2,3,6,0xb, …).
7. Distance from origin vs `param_6` radius; insert into float map (distance key) when accepted.
8. Dump / out-list via map inorder helpers; teardown erase range + free.

**Client call sites:** interact click pick, bound-action poll, several UI/input helpers — **not** only skills.

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `batch_decompile` @ `0x0058cd60` |
| Raw | `raw/aa_0058cd60_FUN_0058cd60.md` |
| Xrefs | `Client_InteractClickPickTarget`, `Client_Input_PollBoundActions`, `FUN_009210e0`, `FUN_00925670`, `FUN_00925820` |
| Tree siblings | `0058d9c0` alloc, `0058def0` insert, `0058da40` rebalance, `0058df60` erase, `0058e020` destroy |

---

## 3. Signature (decomp)

```c
void GatherTargetsRadiusMap(
  int* selfTfid, int modeA, int worldCtx, int* selfObj,
  float* originPose, float radius,
  int flagParam7, int filterMode /*param_8*/, ...,
  char param_10, char param_11);
```

---

## 4. Confidence

| Claim | Confidence |
|---|---|
| Builds local float map | **High** |
| World list walk + multi filters | **High** |
| Vehicle type 0x0e special case | **High** |
| filterMode switch | **High** shape / **Medium** full English |
| Exact out-list layout | **Medium** residual |

**Verdict:** **accept-with-gaps**
