# Review A (reconstruction fidelity): `aa_00727440` Snd_UpdateSounds_UpdateSoundRegions

| Field | Value |
|---|---|
| **Stable ID** | `aa_00727440` |
| **VA** | `0x00727440`–`0x00727b45` exclusive (**1797** B) |
| **Canonical name** | `Snd_UpdateSounds_UpdateSoundRegions` |
| **Prior / alias** | `FUN_00727440`; plate `UpdateSounds::updateSoundRegions` |
| **Review date** | `2026-07-29` (W25-Q OWN-ONLY dual) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_00727440_Snd_UpdateSounds_UpdateSoundRegions.md` |
| **System** | client audio / CSoundManager |
| **Live tools** | Ghidra `decompile_function`, `read_memory`, `get_function_by_address`, callers/callees (no `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Critical-section audio tick** for updateSoundRegions:

1. Gate on enable `mgr+0x258` and dt accum `mgr+0x6c` **> 0.0005**.
2. Enter CS `+0x3f8`; stamp GetTickCount; step subsystem; optional listener push.
3. Profile zone + nest `FUN_007252d0` (hard-kill/regions).
4. Walk slots (count then fixed 0x30): age, volume, spatialize, fade/restart.
5. Maintenance + optional re-arm; zero accum; leave CS; **`ret 0xC`**.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00727440_FUN_00727440.md` (+ W25-Q append) |
| Annotated | `docs/reconstruction/raw/aa_00727440_FUN_00727440.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Snd_UpdateSounds_UpdateSoundRegions.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_00727440.cpp` |
| Function record | `docs/reconstruction/functions/aa_00727440_Snd_UpdateSounds_UpdateSoundRegions.md` |
| Live decompile | ≡ raw CF |
| Live body bytes | `read_memory` @ entry + epilogue |
| String | `read_memory` @ `0x00aa91ac` full plate |
| Threshold | `read_memory` @ `0x00aaab78` → double 0.0005 |
| Nested dual | `aa_007252d0` CSoundManager_TickHardKillAndRegions_Inferred |
| Caller | `FUN_00938380` decompile |

---

## 3. Byte seal (`read_memory`)

| Claim | Evidence | Conf |
|---|---|---|
| SEH prologue | `64 a1 00…` + push `LAB_009b2cff` | **High** |
| Enable test `[ebp+0x258]` | `8a 85 58 02 00 00` | **High** |
| stdcall `ret 0xC` | epilogue `c2 0c 00` | **High** |
| Body span 1797 B | meta exclusive end `00727b45` | **High** |
| Plate string | ASCII at `0x00aa91ac` | **High** |
| Threshold 0.0005 | double at `0x00aaab78` | **High** |
| Decompile ≡ raw ≡ CF intent | three-rep match | **High** |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Gate enable + accum | **Yes** |
| CS enter / leave pair | **Yes** |
| Listener optional path | **Yes** |
| Profile + FUN_007252d0 | **Yes** |
| Slot count walk + 0x30 walk | **Yes** |
| Re-arm when +0x30c==0 | **Yes** |
| Zero +0x6c; ret 0xC | **Yes** |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF outer structure | **High** | sealed three-rep |
| stdcall 3-arg ABI | **High** | `c2 0c 00` |
| Plate name / domain | **High** | string + adjacent CSoundManage |
| Nested regions callee | **High** | dualled sibling |
| Per-slot volume math details | **Med** | helpers not owned |
| Product PDB exact method name | **Probable** | plate-backed |
| Runtime tick timing proven | **Open** | no Launcher |

---

## 6. Gaps

1. Full semantics of nested volume/spatialize helpers (owned by other partitions).
2. Exact class ownership spelling (`UpdateSounds` vs `CSoundManager` method).
3. Runtime / bit-exact / differential — open (no Launcher).

**Verdict:** **accept-with-gaps** — ABI, gate, CS, plate string, nested call, slot structure sealed; helper deep-dives residual.
