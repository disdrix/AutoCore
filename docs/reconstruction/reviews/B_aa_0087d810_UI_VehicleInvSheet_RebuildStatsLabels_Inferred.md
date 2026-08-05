# Review B (skeptical / adversarial): `aa_0087d810` UI_VehicleInvSheet_RebuildStatsLabels_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0087d810` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0087d810_UI_VehicleInvSheet_RebuildStatsLabels_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | C2S equip / cast packet | No bitstream send in body | **Falsified** |
| 2 | Recomputes hardpoint mode 0/1/2 | That is `00862b70` | **Falsified** |
| 3 | Runs with null local player | Early-out `DAT_00d1b6d8==0` | **Falsified** |
| 4 | Always shows DPS block | Empty bind clears labels; full path null-checks each child | **Partial** — gated |
| 5 | `g_flMultiKillCountBlend` name means multi-kill UI here | Shared float pool used as scale in one tint path | **Do not seal product name** |
| 6 | Size-class strings differ for cases 2 vs 3 | Both use same "(Medium & Large…)" string | **Survives** — string reuse sealed |
| 7 | Bit-exact entire clean scaffold | ~0x28be body + decompiler noise | **Reject full bit-exact claim** |

---

## 2. Live ≡ raw (structural)

Live decompile matches raw: same gates, empty-bind clear ladder, full-path widget fills, sealed strings, vehicle pool callees. Prefer assembly for entry ABI (`sub esp,0x144` + stack sheet).

Constants cross-check (`read_memory`):

| VA | Value |
|---|---|
| `0x00a110d8` | **10.0f** |
| `0x00a1e3f0` | 1.35 / 1.15 / 1.0 / 1.23 class mults |
| `0x00aaa664` | ~1e-4f |

---

## 3. Surviving contract for AutoCore

```
// Client UI only
void RebuildVehicleInvSheetStats(Sheet* sheet);
// no-op without UI global / local player
// if !sheet->bound(+0x514): clear label children +0x55c..+0x580
// else fill name/DPS/power-heat/range/resists/size footer from bound + DAT_00d1b6d8 pools
```

**Verdict:** **accept-with-gaps**.
