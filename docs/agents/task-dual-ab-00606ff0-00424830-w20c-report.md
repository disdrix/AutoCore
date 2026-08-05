# Dual A/B report — W20-C OWN-ONLY (`0x00606ff0`, `0x00424830`)

**Date:** 2026-07-29  
**Agent:** W20-C OWN-ONLY  
**Scope:** OWN ONLY VAs `0x00606ff0`, `0x00424830`. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / parent ledgers.  
**Ghidra:** `decompile_function` + `read_memory` (+ function meta / xrefs / complete analysis). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict per VA

| Unit | Verdict |
|------|---------|
| `aa_00606ff0` Outpost_PreRecastBankWalk | **accept-with-gaps** — **thiscall+faction, bank/TFID, flag==0, vfunc 0x220(skillId,1) sealed; +0x220 English residual** |
| `aa_00424830` Rng_Mt19937_Extract | **accept** — **EAX state, twist-on-empty, classic temper sealed** |

---

## `aa_00606ff0` — Outpost_PreRecastBankWalk

### Sealed facts

1. **Body:** `0x00606ff0`–`0x006070d6` exclusive (**230** B). Epilogue **`ret 4`** (`c2 04 00`); following `cc` pad.

2. **ABI:** MSVC **`__thiscall`** — **ECX = outpost**, stack **`factionIndex`**, bare void. Decompiler thiscall matches bytes.

3. **Faction gate:** process only when `0 <= faction < 4`; else return.

4. **Layout:** `factionBase = this + faction * 0x48`; skill bank begin/end `+0xd4/+0xd8` (stride **0x10**); TFID begin/end `+0xb4/+0xb8` (stride **8**).

5. **Algorithm:** for each bank entry with **`flag@+0x0C == 0`** (no ratio gate): for each TFID → `CVOGReaction_ResolveObjectTarget(0, lo, hi)` → `vtbl+0x1ec` container → MI-adjust → **`vtbl+0x220(skillId@+0, 1)`**.

6. **Callees:** `CVOGReaction_ResolveObjectTarget` @ `0x004bae70` only (virtuals not listed).

7. **Callers (2):** `Outpost_UpdateBeaconShareRatio` (`FUN_006078e0` @ `0060799a`) — on ratio change, **before** BeaconShare; CaptureOutpost (`FUN_006082e0` @ `00608543`) — outgoing faction teardown.

8. **Distinct from** `Outpost_CastSkillsForBeaconShare` (`0x006070e0`) — no ResolveSkillTargets, no ratio threshold, no CastSkillOnTarget batch.

9. **Name:** structural `Outpost_PreRecastBankWalk` (matches prior W19-O residual label).

### Gaps

1. Product/PDB method spelling.  
2. Product English for `vtbl+0x220(skillId, 1)` (wire remove family uses `(id, 0)`).  
3. Runtime / bit-exact / differential — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_00606ff0_Outpost_PreRecastBankWalk.md` | **accept-with-gaps** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_00606ff0_Outpost_PreRecastBankWalk.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_00606ff0_Outpost_PreRecastBankWalk.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00606ff0_Outpost_PreRecastBankWalk.md` |
| Function record | `docs/reconstruction/functions/aa_00606ff0_Outpost_PreRecastBankWalk.md` |
| Scaffold alias record | `docs/reconstruction/functions/aa_00606ff0_FUN_00606ff0.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Outpost_PreRecastBankWalk.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_00606ff0.cpp` |
| Raw | `docs/reconstruction/raw/aa_00606ff0_FUN_00606ff0.md` |
| Annotated | `docs/reconstruction/raw/aa_00606ff0_FUN_00606ff0.annotated.md` |

---

## `aa_00424830` — Rng_Mt19937_Extract

### Sealed facts

1. **Body:** `0x00424830`–`0x00424882` exclusive (**82** B). Final **`c3`**; following `cc` pad.

2. **ABI:** **EAX = `Mt19937State*`** on entry (`mov esi, eax`); bare **`ret`**; returns tempered **`uint32` in EAX**. Not ECX-thiscall. Distinct from twist’s **ESI** entry.

3. **Layout:** cursor `+0x9c0`, remaining `+0x9c4`, `mt[624]` @ +0; object size **0x9c8** (sibling-agreed).

4. **Algorithm:** if `remaining==0` → `Rng_Mt19937_Twist` (`0x004248c0`); `--remaining`; `y = *cursor++`; temper; return `y`.

5. **Temper (sealed):**  
   `y ^= y>>11;`  
   `y ^= (y & 0xff3a58ad)<<7;`  
   `y ^= (y & 0xffffdf8c)<<15;`  
   `return (y>>18) ^ y;`  
   ≡ classic MT19937 (`0x9d2c5680` / `0xefc60000` post-shift form).

6. **Callees:** `FUN_004248c0` / `Rng_Mt19937_Twist` only.

7. **Callers:** **34** UNCONDITIONAL_CALL xrefs (sound, humor, UI, table wrappers, …).

8. **Name:** `Rng_Mt19937_Extract` (family with Seed / Twist).

### Gaps

1. Product/PDB symbol spelling.  
2. Per-caller state-instance identity.  
3. Runtime / bit-exact / differential — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_00424830_Rng_Mt19937_Extract.md` | **accept** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_00424830_Rng_Mt19937_Extract.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_00424830_Rng_Mt19937_Extract.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00424830_Rng_Mt19937_Extract.md` |
| Function record | `docs/reconstruction/functions/aa_00424830_Rng_Mt19937_Extract.md` |
| Scaffold alias record | `docs/reconstruction/functions/aa_00424830_FUN_00424830.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Rng_Mt19937_Extract.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_00424830.cpp` |
| Raw | `docs/reconstruction/raw/aa_00424830_FUN_00424830.md` |
| Annotated | `docs/reconstruction/raw/aa_00424830_FUN_00424830.annotated.md` |

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`

---

## AutoCore impact

### Outpost_PreRecastBankWalk (`0x00606ff0`)

- Keep **separate** from BeaconShare cast: this unit only walks flag==0 bank and invokes host `+0x220(skillId, 1)`.
- On beacon-share ratio change: call this **then** `Outpost_CastSkillsForBeaconShare` (retail order).
- CaptureOutpost: call with **old** faction among teardown before faction rewrite.
- Do not invent ratio gate or batch cast inside this VA.
- Port must preserve **mode 0** ResolveObjectTarget (≠ Faction mode 1).

### Rng_Mt19937_Extract (`0x00424830`)

- Client PRNG extract: **EAX state**, temper as sealed, twist when remaining hits 0.
- Do not substitute libc `rand` or alter temper masks if streams must match retail.
- Pair with `Rng_Mt19937_Twist` / `Rng_Mt19937_Seed` for full engine; object **0x9c8**.

---

## Sibling context (not owned)

| VA | Role |
|---|---|
| `0x006070e0` | `Outpost_CastSkillsForBeaconShare` |
| `0x006078e0` | `Outpost_UpdateBeaconShareRatio` |
| `0x006082e0` | CaptureOutpost path |
| `0x00606d70` | `Outpost_CastSkillsForFaction` |
| `0x004248c0` | `Rng_Mt19937_Twist` |
| `0x00424890` | `Rng_Mt19937_Seed` |
| `0x004bae70` | `CVOGReaction_ResolveObjectTarget` |

---

## This report

`docs/agents/task-dual-ab-00606ff0-00424830-w20c-report.md`
