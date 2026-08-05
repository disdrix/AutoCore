# Review A (reconstruction fidelity): `aa_00574e60` ConvoyRoster_CountEligibleMembers_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00574e60` |
| **VA** | `0x00574e60` |
| **Body span** | `0x00574e60` – `0x00574f6d` (exclusive end past final `ret 4`) |
| **Canonical name** | `ConvoyRoster_CountEligibleMembers_Inferred` |
| **Prior / alias** | `FUN_00574e60`; `Named_CalleeOf_CVOGCombat_OnDeathAwardKillXp_00574e60` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A/B **create** — live Ghidra) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00574e60_ConvoyRoster_CountEligibleMembers_Inferred.md` |
| **System** | missions-progression / kill-XP convoy |
| **Dual status** | **Present (create)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Compute convoy XP-share divisor / eligible-member count** for the killer’s roster:

1. Start from roster byte `this+0x1d8` (unsigned → uint working count).
2. Sample reference position from stack arg object `param_2` via adjusted-this vtbl **`+0x1a0`** (returns `float*` pos; use `x=*p`, `z=p[2]`).
3. Walk **4** slots at `this+0x1a0`, stride **`0x10`** (same layout as `FUN_00574760`).
4. For each **non-null** member:
   - Get member pos via same vtbl `+0x1a0`.
   - Get soft/out flag via vtbl **`+0x198`** on member adjusted-this.
   - If `flag != 0` **OR** horizontal distance `sqrt(dx²+dz²) ≥ DAT_00aaa8a8` (**300.0f**), **decrement** working count.
5. Clamp: if count `< 1`, set to **1**.
6. Return count (`uint`).

**Sole caller:** `CVOGCombat_OnDeathAwardKillXp` — result passed into `CVOGCombat_CalculateAndAwardKillXP` as convoy-member count for share blending.

Name **Inferred** (no string/RTTI on VA); algorithm **High** from decompile + constant read.

---

## 2. Inspected artifacts

| Artifact | Path / source | This pass |
|---|---|---|
| Live decompile | `batch_decompile` `0x00574e60` | **≡ raw** |
| Live bytes head | `read_memory` @ `0x00574e60` | prologue + `movzx` from `+0x1d8` |
| Live bytes end | `read_memory` @ `0x00574f60` | `mov eax,1; …; ret 4` clamp/epilogue |
| Constant | `read_memory` `DAT_00aaa8a8` | `00 00 96 43` = **300.0f** |
| Callers / xrefs | live | **1** — OnDeathAwardKillXp @ `0x004dab30` |
| Slot sibling | `aa_00574760` | same `+0x1a0` / ×4 |
| Guard sandwich | `00574900` / `00574910` | enter / leave no-ops |
| Raw / annotated / clean | scaffold | CF match (scaffold types) |

**Not performed:** Launcher, runtime multi-member capture, Ghidra rename, ledgers.  
**Note:** `get_function_callees` returned empty (indirect vtbl only; SQRT intrinsic) — expected.

---

## 3. Live decompile (authoritative ≡ raw)

```c
uint __thiscall FUN_00574e60(int param_1, int param_2)
{
  float fVar1, fVar2, fVar3, fVar4;
  int iVar5;
  char cVar6;
  float *pfVar7;
  int *piVar8;
  int iVar9;
  uint local_30;
  int iStack_24;

  local_30 = (uint)*(byte *)(param_1 + 0x1d8);
  pfVar7 = (float *)(**(code **)(*(int *)(*(int *)(*(int *)(param_2 + 4) + 4) + 4 + param_2) + 0x1a0))();
  fVar1 = *pfVar7;
  fVar2 = pfVar7[2];
  iVar9 = 0;
  piVar8 = (int *)(param_1 + 0x1a0);
  iStack_24 = 4;
  do {
    if (((-1 < iVar9) && (iVar9 < 4)) && (iVar5 = *piVar8, iVar5 != 0)) {
      pfVar7 = (float *)(**(code **)(*(int *)(*(int *)(*(int *)(iVar5 + 4) + 4) + 4 + iVar5) + 0x1a0))();
      fVar3 = pfVar7[2];
      fVar4 = *pfVar7;
      cVar6 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar5 + 4) + 4) + 4 + iVar5) + 0x198))();
      if ((cVar6 != '\0') ||
         (DAT_00aaa8a8 <= SQRT((fVar2 - fVar3)*(fVar2 - fVar3) + (fVar1 - fVar4)*(fVar1 - fVar4)))) {
        local_30 = local_30 - 1;
      }
    }
    iVar9 = iVar9 + 1;
    piVar8 = piVar8 + 4;   // +0x10 bytes
    iStack_24 = iStack_24 - 1;
  } while (iStack_24 != 0);
  if ((int)local_30 < 1) {
    local_30 = 1;
  }
  return local_30;
}
```

**ABI (High):** `__thiscall`; stack arg `param_2`; epilogue **`ret 4`**.

---

## 4. Confidence table

| Claim | Confidence | Evidence |
|---|---|---|
| Start count = `*(u8*)(this+0x1d8)` | **High** | decompile + `movzx` at head |
| 4 slots @ `this+0x1a0` stride 0x10 | **High** | loop + sibling GetMember |
| Null slot skipped (no decrement) | **High** | `iVar5 != 0` gate |
| Decrement when flag≠0 **OR** dist ≥ 300 | **High** | CF + `read_memory` constant |
| Dist uses X/Z only (`*p`, `p[2]`) | **High** | decompile |
| Pos / flag via adjusted-this vtbl +0x1a0 / +0x198 | **High** | standard ND pattern |
| Clamp min 1 | **High** | final `if < 1 → 1` + epilogue `mov eax,1` path |
| Sole OnDeathAward caller | **High** | xrefs |
| Return feeds CalculateAndAwardKillXP convoy count | **High** | parent decompile |
| Soft-flag semantics (English) | **Probable** | same slot as award-loop vehicle flag at callers, but **here** invoked on **member** adjusted-this — not `member+0x250` vehicle |
| `this` = convoy roster | **Probable** | layout shared with GetMember; ECX from `+0xcb0` path |
| `param_2` = reference character (killer) for origin pos | **High** at sole call site | `FUN_00574e60(pvVar5)` killer |
| Product name | **Low / Inferred** | no string |
| Runtime multi-member golden | **Open** | policy |

---

## 5. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Load +0x1d8 seed count | **Yes** |
| Ref pos from param_2 vtbl+0x1a0 | **Yes** |
| 4-iter slot walk | **Yes** |
| Null skip | **Yes** |
| Flag OR far → decrement | **Yes** |
| Clamp ≥ 1 | **Yes** |
| Return count | **Yes** |

### Clean fidelity

| Aspect | Fidelity |
|---|---|
| CF / formula | **Good** (scaffold preserves) |
| Named fields / helpers | **Gap** — raw offsets / vtbl numbers |
| SQRT / DAT naming | **Gap** — still DAT / SQRT |

---

## 6. Field / constant map

| Offset / symbol | Role |
|---|---|
| `this+0x1d8` | `u8` roster headcount seed |
| `this+0x1a0 + i*0x10` | slot member ptr (dword0) |
| vtbl `+0x1a0` | get world pos `float*` (x, ?, z) |
| vtbl `+0x198` | soft/out byte flag |
| `DAT_00aaa8a8` | **300.0f** convoy radius (shared with OnDeathAward / Collect) |

---

## 7. Residual disposition

| Topic | Disposition |
|---|---|
| Algorithm CF + clamp | **Sealed High** |
| Radius 300.0f | **Sealed High** |
| Slot layout shared with GetMember | **Sealed High** |
| Sole caller + XP-share use | **Sealed High** |
| Exact English for vtbl+0x198 | **Probable** |
| Whether empty slots imply +0x1d8 already accounts for them | **Probable** (behavioral) |
| Product class name | **Open / Inferred** |
| Runtime | **Open** |

**Verdict:** **accept-with-gaps** — full static algorithm sealed; type names + flag English + runtime open.
