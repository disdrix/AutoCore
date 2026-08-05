# Dual A/B report — W25-Q OWN-ONLY (`0x0071b430`, `0x00727440`)

**Date:** 2026-07-29  
**Agent:** W25-Q OWN-ONLY  
**Scope:** OWN ONLY VAs `0x0071b430`, `0x00727440`. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / parent ledgers.  
**Ghidra:** `decompile_function` + `read_memory` (+ function meta / callers / callees). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict per VA

| Unit | Verdict |
|------|---------|
| `aa_0071b430` DES_BuildIPFPLookupTables | **accept-with-gaps** — **IP/FP nibble LUT builder CF, FIPS sources, clear size, cdecl ABI, sole-caller sealed; post-init bank KAT open** |
| `aa_00727440` Snd_UpdateSounds_UpdateSoundRegions | **accept-with-gaps** — **stdcall ret 0xC audio tick, 0.0005 gate, CS, plate string, nested 007252d0 sealed; deep helper semantics residual** |

---

## `aa_0071b430` — DES_BuildIPFPLookupTables

### Sealed facts

1. **Body:** `0x0071b430`–`0x0071b59d` exclusive (**365** B). Final `add esp,8; ret`; following `cc` pad.

2. **ABI:** **cdecl** two stack args (`dst`, `perm`); **bare `ret`**. Leaf (no callees).

3. **Clear:** `ecx=0x200` dwords → **0x800-byte** destination LUT.

4. **Algorithm:** for nibble-group 0..15 × nibble 0..15 × 64 perm bits (unrolled ×4): if FIPS source bit falls in group and nibble mask matches, OR output bit mask into `dst[(group*16+nibble)*8 + (bit>>3)]`.

5. **Sources:** `DAT_00afca50` = FIPS **IP** (exact); `DAT_00afca90` = FIPS **FP** (exact). Masks `DAT_00afcd68` (0x80..0x01), `DAT_00afcd88` (0x08..0x01).

6. **Caller (sole):** `DES_InitializeCipher` — `(&DAT_00d16ef0,&DAT_00afca50)` then `(&DAT_00d12690,&DAT_00afca90)`.

7. **Consumer:** `DES_PermuteBlock` uses filled IP/FP banks (not this VA).

8. **Distinct from** `DES_BuildSBoxLookupTables` (`0071bdd0`) and `DES_BuildPermutationP_Tables` (`0071b5a0`).

9. **Name:** structural `DES_BuildIPFPLookupTables`; scaffold `FUN_0071b430`.

### Gaps

1. Post-init dump of filled banks vs independent FIPS expand (bit-exact KAT).  
2. Product/PDB symbol spelling.  
3. Runtime / bit-exact / differential — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_0071b430_DES_BuildIPFPLookupTables.md` | **accept-with-gaps** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_0071b430_DES_BuildIPFPLookupTables.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_0071b430_DES_BuildIPFPLookupTables.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0071b430_DES_BuildIPFPLookupTables.md` |
| Function record | `docs/reconstruction/functions/aa_0071b430_DES_BuildIPFPLookupTables.md` |
| Scaffold alias record | `docs/reconstruction/functions/aa_0071b430_FUN_0071b430.md` |
| Clean | `docs/reconstruction/reconstructed-exact/DES_BuildIPFPLookupTables.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_0071b430.cpp` |
| Raw | `docs/reconstruction/raw/aa_0071b430_FUN_0071b430.md` |
| Annotated | `docs/reconstruction/raw/aa_0071b430_FUN_0071b430.annotated.md` |

---

## `aa_00727440` — Snd_UpdateSounds_UpdateSoundRegions

### Sealed facts

1. **Body:** `0x00727440`–`0x00727b45` exclusive (**1797** B). SEH prologue; final **`ret 0xC`**.

2. **ABI:** **stdcall** three args: `mgr*`, `uint flag`, `float dt`.

3. **Gate:** `*(char*)(mgr+0x258)!=0` AND `(mgr+0x6c)+dt` **> double 0.0005** (`_DAT_00aaab78`).

4. **CS:** `EnterCriticalSection` / `LeaveCriticalSection` at `mgr+0x3f8`; GetTickCount → `+0x3dc`.

5. **Plate:** `"UpdateSounds::updateSoundRegions()"` @ `0x00aa91ac` (adjacent `CSoundManage…`); profiler enter/leave via `FUN_00786a00` / `FUN_00786990`.

6. **Nest:** `FUN_007252d0(flag, accum)` = hard-kill + regions (dualled `aa_007252d0`).

7. **Slots:** table `@+0x31c`, fixed walk **0x30**, active count `@+0x210`; volume/spatialize/fade helpers.

8. **Caller (sole):** `FUN_00938380` (client tick path).

9. **Name:** `Snd_UpdateSounds_UpdateSoundRegions` (plate-backed); scaffold `FUN_00727440`.

### Gaps

1. Full semantics of nested volume/spatialize helpers (other ownership).  
2. Exact product class/method spelling residual (`UpdateSounds` vs `CSoundManager`).  
3. Runtime / bit-exact / differential — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_00727440_Snd_UpdateSounds_UpdateSoundRegions.md` | **accept-with-gaps** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_00727440_Snd_UpdateSounds_UpdateSoundRegions.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_00727440_Snd_UpdateSounds_UpdateSoundRegions.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00727440_Snd_UpdateSounds_UpdateSoundRegions.md` |
| Function record | `docs/reconstruction/functions/aa_00727440_Snd_UpdateSounds_UpdateSoundRegions.md` |
| Scaffold alias record | `docs/reconstruction/functions/aa_00727440_FUN_00727440.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Snd_UpdateSounds_UpdateSoundRegions.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_00727440.cpp` |
| Raw | `docs/reconstruction/raw/aa_00727440_FUN_00727440.md` |
| Annotated | `docs/reconstruction/raw/aa_00727440_FUN_00727440.annotated.md` |

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`

---

## AutoCore impact

### DES_BuildIPFPLookupTables (`0x0071b430`)

- Port as **one-shot DES init helper** only — expand FIPS IP/FP into 0x800-byte nibble LUTs.
- Do **not** substitute S-box builder (`0071bdd0`) or P-builder (`0071b5a0`).
- Preserve **cdecl** two-arg form; call IP then FP from `DES_InitializeCipher` order.
- Runtime apply of IP/FP remains `DES_PermuteBlock` — do not invent apply inside this VA.
- Before claiming bit-exact crypto, dump filled `d16ef0` / `d12690` and KAT against independent expand.

### Snd_UpdateSounds_UpdateSoundRegions (`0x00727440`)

- Client-only audio tick; **not** a sector/server concern unless mirroring client UX audio.
- Preserve **stdcall ret 0xC**, enable gate, **0.0005** accum, and CS `@+0x3f8`.
- Keep nested hard-kill/regions as call to `007252d0` (do not flatten wrong offsets into this frame).
- Slot table size **0x30** @ `+0x31c` is load-bearing.

---

## This report

`docs/agents/task-dual-ab-0071b430-00727440-w25q-report.md`
