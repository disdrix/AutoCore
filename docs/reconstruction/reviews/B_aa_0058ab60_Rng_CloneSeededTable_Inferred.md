# Review B (skeptical / adversarial): `aa_0058ab60` Rng_CloneSeededTable_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0058ab60` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (dual A/B — wave3 skills helper) |
| **Counterpart** | `reviews/A_aa_0058ab60_Rng_CloneSeededTable_Inferred.md` |
| **Verdict** | **accept-with-gaps** on behavior/ABI/sizes; product name remains Inferred |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Function is no-op / returns seed unchanged | **Falsified** — `new[](0x4b0)` + 300-dword memcpy from table |
| 2 | Returns a pointer **into** the global table (not a clone) | **Falsified** — destination is heap `puVar1`; source only for read |
| 3 | Index is **dword**-based (`*4`) | **Falsified** — decompile `cursor * 2`; wrap headroom 600 ushorts |
| 4 | `0x4b0` is 1200 dwords / mis-sized | **Falsified** — `0x4b0` bytes = 300 dwords = 1200 B |
| 5 | Wrap uses `0x80000` (u32 count) | **Falsified** — compare is `cursor + 600 > 0xFFFFF` |
| 6 | Pure / no global side effects | **Falsified** — forces `+0x0C = seed`, then `+0x0C += 1` |
| 7 | `CVOGReaction_RandomUnitScalar` returns a float unit sample | **Falsified for this use** — returns `&DAT_00d20c1c` singleton (name is historical misnomer; CHANGE_LOG already notes) |
| 8 | Only used from HB ctor | **Falsified** — **12** CALL xrefs; HB is one of them |
| 9 | ApplyEffects treats buffer as dword[] only | **Falsified** — `MOV DX,[EAX]` loads first **ushort** |
| 10 | Product name is retail `CVOG…` known | **Unproven** — no string/RTTI; `_Inferred` required |
| 11 | Table is C `rand()` | **Falsified** — MT19937 constants in fill path (`0x6c078965`, 624 state, temper shift chain) |
| 12 | Seed formal ignored when cursor already set | **Falsified** — body **always** writes `param_1` to `+0x0C` first |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Alloc size / copy count | **Confirmed** | Wrong heap free size / dice walk bounds |
| Ushort index scale (`*2`) | **Confirmed** | Off-by-2× table reads → desync skill rolls |
| Wrap `0xFFFFF` / +600 | **Confirmed** | OOB read past 2 MiB table |
| Singleton offsets +8/+0xC | **Confirmed** | Port touches wrong fields |
| cdecl 1-arg / EAX return | **Confirmed** | Wrong calling convention in port |
| HB `+0x6a0` / `+0x6a8` | **Confirmed** | Skill HB layout wrong |
| Product symbol | Inferred | Cosmetic rename only |
| Full MT temper ≡ every table dword | **High** (fill unit) | Bit-exact replay; out of this unit |
| Orphan parent function names | Open | Completeness of caller map only |

---

## 3. Cross-check

```
Decompile 0058ab60:     new[] 0x4b0; set +0xC; wrap; copy 300; ++cursor
RandomUnitScalar:       lazy-init DAT_00d20c34 bit0 → FUN_007a42d0; return &DAT_00d20c1c
FUN_007a4200:           new[] 0x200000 @ +8; fill 0x80000 tempered u32; +0xC = 0
FUN_00424890/c0:        MT19937 init/twist (0x270 state, 0x6c078965, 0x9908b0df)
HB ctor 005789dc:       MOV [EBP+0x6a8],EAX; PUSH; CALL 0058ab60; MOV [EBP+0x6a0],EAX
ApplyEffects 0055396c:  CALL; MOV DX,[EAX]; FUN_00553240(..., DX, 0); later delete[]
00615020:               clone once; walk ushort*; FUN_00589b80(*slice); delete[] at exit
```

**Attack on “seed*2 is decompiler artifact”:** wrap constant is **600**, not 300. If index were dword-scaled, headroom would be 300 and source scale `*4`. Both constants agree on **ushort** domain. ApplyEffects/`00615020` ushort consumers corroborate.

**Attack on “cursor+1 means advances by one clone window”:** body adds **1**, not 300/600. After an explicit-seed clone, global cursor sits at `seed+1` (or `1` if wrapped to 0 then +1). Subsequent **unseeded** consumers of the singleton see that cursor; this unit always re-seeds from `param_1` first.

**Attack on “HB keeps live shared table pointer”:** store is return of `new[]`; independent heap clone. Free ownership lives in HB lifetime (out of unit).

---

## 4. Surviving contract for AutoCore

```
// Global RNG singleton (DAT_00d20c1c), after init:
//   +0x08 → uint8_t table[0x200000]  // filled as 0x80000 tempered u32
//   +0x0C → int cursor               // ushort index into table

uint32_t* Rng_CloneSeededTable_Inferred(uint32_t seedIndex) {
  uint32_t* out = (uint32_t*)operator_new[](0x4b0);   // 300 dwords
  RngSingleton* rng = CVOGReaction_RandomUnitScalar();  // &DAT_00d20c1c
  rng->cursor = (int)seedIndex;
  if (rng->cursor + 600 > 0xFFFFF)
    rng->cursor = 0;
  const uint32_t* src = (const uint32_t*)(rng->table + rng->cursor * 2);
  for (int i = 0; i < 300; ++i)
    out[i] = src[i];
  rng->cursor += 1;
  return out;   // caller free[]; often consumed as uint16_t[600]
}

// HB ctor (0x005788d0):
//   hb+0x6a8 = arg7;
//   hb+0x6a0 = Rng_CloneSeededTable_Inferred(arg7);
```

---

## 5. Residual uncertainty

| # | Item | Blocks behavior seal? |
|---|---|---|
| R1 | PDB / product C++ name | **No** |
| R2 | Orphan parents of 3 xrefs | **No** |
| R3 | Free path for `hb+0x6a0` | **No** (storage sealed) |
| R4 | Bit-exact MT fill vs live table | **No** for clone CF; yes for replay |
| R5 | Semantic label “dice” vs “rng” | **No** |
| R6 | Whether wrap uses signed vs unsigned compare edge at INT_MAX | Mild — decompile uses int compare; seeds expected small |

---

## 6. Concrete checks performed

1. Live decompile `0x0058ab60` — match raw capture body.
2. Decompile `CVOGReaction_RandomUnitScalar`, `FUN_007a42d0`, `FUN_007a4200`, `FUN_00424890`, `FUN_004248c0`.
3. `get_xrefs_to` → 12 CALL sites; `get_assembly_context` on all 12.
4. `get_function_callers` → 9 named; 3 orphan.
5. `read_memory` `0x00d20c1c` length 32 — static BSS zeros (init at runtime).
6. Cross-check HB ctor dual residual claim #10 (no-op) against this unit — **falsified**, behavior High.
7. Sample consumers: ApplyEffects first-ushort; `FUN_00615020` ushort walk + `delete[]`.

---

## 7. Verdict

**accept-with-gaps** for `Rng_CloneSeededTable_Inferred`: sealed seeded ushort-window clone into `0x4b0` heap with global cursor mutation; HB `+0x6a0`/`+0x6a8` contract sealed. Product name and orphan parents remain open.
