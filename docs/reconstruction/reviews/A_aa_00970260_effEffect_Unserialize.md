# Review A (reconstruction fidelity): `aa_00970260` effEffect_Unserialize

| Field | Value |
|---|---|
| **Stable ID** | `aa_00970260` |
| **VA** | `0x00970260` |
| **Canonical name** | `effEffect_Unserialize` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (faithfulness of clean / annotated / plate to live decompile + strings + p-code) |
| **Counterpart** | `reviews/B_aa_00970260_effEffect_Unserialize.md` |
| **System** | `graphics-effects` |
| **Owner** | dual-w6-eff (OWN-ONLY this VA) |
| **Verdict** | **accept-with-gaps** — chunk tags, version gates, PARM type switch, error strings, and success/fail returns sealed; many FUN_* callees and full PARM body layout remain open |

---

## 1. Purpose

`effEffect::Unserialize` — stream an **EFCT** (`0x45464354`, file bytes `TCFE`) effect chunk from a `stoChunkReader`, resolve the effect by name (v2 inline string vs v3 nested path), then consume a sequence of **PARM** (`0x5041524d`, file bytes `MRAP`) parameter chunks typed 1..5 (bool / int / float-array / inline string / nested ISTR string). Special-case: bool param named `AlphaTestEnable` nonzero → register technique alias `Alpha_Test` and set `*(uint8_t*)(param_1 + 1) = 1`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00970260_effEffect_Unserialize.md` |
| Annotated | `docs/reconstruction/raw/aa_00970260_effEffect_Unserialize.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/effEffect_Unserialize.cpp` |
| Function record | `docs/reconstruction/functions/aa_00970260_effEffect_Unserialize.md` |
| Three-rep | `decompile_function` + `force_decompile` (identical) + `read_memory` strings + basic p-code tag constants |
| Live Ghidra | Body `0x00970260`–`0x00970852`; plate owns string @ `0x00a9ec1c` |

**Live Ghidra performed this pass** — not scaffold-only.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Name `effEffect_Unserialize` / plate source path | **Confirmed** | plate + strings under `...\Effects\effEffect.cpp` |
| Signature `(effEffect* out, stoChunkReader* reader)` shape | **High** | decomp `param_1` / `param_2`; `param_2+0x4044` stream mode branch; not ABI-byte sealed |
| Outer tag `local_104 == 0x45464354` (**EFCT**) | **Confirmed** | decomp + p-code const `45464354` |
| Loop sibling tag `iVar3 == 0x5041524d` (**PARM**) | **Confirmed** | decomp + p-code const `5041524d` |
| Version `1` → DX8 reject (line `0x30f`) | **Confirmed** | string @ `0x00a9ebe8` |
| Versions `2` and `3` accepted (`1 < ver < 4`) | **Confirmed** | decomp gate |
| Other version → invalid-version log (line `0x3ac`) | **Confirmed** | string @ `0x00a9eba8` |
| Wrong tag → invalid-TAG log (line `0x308`) | **Confirmed** | string @ `0x00a9ec1c` (`read_memory`) |
| v2 effect name via `FUN_00439a20` + SSO string | **High** | SSO threshold `local_128 < 0x10` |
| v3 effect name via `FUN_0096a7f0` | **High** | alternate path when `local_100 != 2` inside accepted band |
| Resolve via `FUN_009701d0(&local_120)`; fail if `< 0` | **High** | then fall through to failure return |
| PARM loop: peek `FUN_0076a900`; non-PARM → finalize + **return 0** | **Confirmed** | success path |
| PARM body: name then `valueType` `local_118` switch 1..5 | **Confirmed** | decomp switch |
| Type 1 bool: `AlphaTestEnable` + nonzero → `FUN_0096ff50("Alpha_Test")` + `param_1[1]=1` | **Confirmed** | strings @ `0x00a9ebd8` / `Alpha_Test` after source path |
| Type 3 float array uses `stoChunkReader_readF32Array` | **Confirmed** | named callee |
| Type 4 string: `strstr(...,"Phase")` forks apply path | **Confirmed** | decomp |
| Type 5 nested ISTR when `local_b4==2` else inline string | **High** | plate claims ISTR; branch sealed, chunk-id not re-read in this unit |
| Fail paths return `0xffffffff`; success `0` | **Confirmed** | dual exits |
| Callers: `gfxGeometryPiece_Unserialize` ×2, `FUN_0095ef50` ×7 | **Confirmed** | 9 UNCONDITIONAL_CALL xrefs |
| Plate notes on vehicle tint / effects.glm | **Tentative** | domain commentary, not executed in this body |
| Individual FUN_* semantics (apply, lookup, leave-scope) | **Open** | OWN-ONLY — not dualed here |

---

## 4. Control flow: clean ≡ raw ≡ live decompile

| Stage | Match |
|---|---|
| SEH / `stoChunkReader_EnterChunkScope` entry | **Yes** |
| Tag gate EFCT | **Yes** |
| Version 1 / 2–3 / else | **Yes** |
| Name load v2 vs v3 | **Yes** |
| `FUN_009701d0` resolve fail → error return | **Yes** |
| PARM loop until non-PARM → success 0 | **Yes** |
| switch types 1..5 | **Yes** |
| AlphaTestEnable special case | **Yes** |
| Type 3 float submodes (`local_84` 0/1/2/3) + unimplemented log `0x374` | **Yes** |
| Type 5 fail → error path | **Yes** |
| Shared fail: `vog_LogMessage` + leave scope + return `-1` | **Yes** |
| Clean is scaffold (FUN_* preserved) | **Yes** — CF-preserving, not modernized |

---

## 5. Seal block (this unit only)

```
effEffect_Unserialize(effect*, reader*) -> u32:
  EnterChunkScope(reader)
  tag = reader.currentTag   # observed as local_104 after enter
  if tag != 0x45464354:     # 'EFCT' / file "TCFE"
    log(effEffect.cpp, 0x308, "Invalid TAG unserializing effEffect"); return -1
  ver = reader.currentVersion  # local_100
  if ver == 1:
    log(..., 0x30f, "DX8 geo files are not supported, please re-export"); return -1
  if !(1 < ver < 4):        # accept only 2 and 3
    log(..., 0x3ac, "Invalid chunk version unserializing effEffect"); return -1
  nameId = (ver==2) ? hash/intern(inline string) : FUN_0096a7f0(...)
  if FUN_009701d0(&nameId) < 0: return -1
  loop:
    next = FUN_0076a900()   # peek next chunk tag
    if next != 0x5041524d:  # 'PARM' / file "MRAP"
      finalize; return 0    # success
    EnterChunkScope(reader); read param name + valueType
    switch valueType:
      1: bool; if name=="AlphaTestEnable" && val: setAlphaTest path; effect+1 = 1
      2: int apply
      3: float-array apply (submodes; may readF32Array)
      4: string; if name contains "Phase": special apply else normal
      5: string resource; fail if bind < 0 → return -1
  # SEH leave on all exits
```

### String cluster (read_memory)

| VA | String |
|---|---|
| `0x00a9eba8` | `Invalid chunk version unserializing effEffect` |
| `0x00a9ebd8` | `AlphaTestEnable` |
| `0x00a9ebe8` | `DX8 geo files are not supported, please re-export` |
| `0x00a9ec1c` | `Invalid TAG unserializing effEffect` |
| `0x00a9ec40` | `C:\vog\1_code\palantir\palantir\graphics\Effects\effEffect.cpp` |
| next | `Alpha_Test` (adjacent after source path) |

### FourCC endianness note

Decompiler compares host **u32** tags `0x45464354` / `0x5041524d` (= ASCII `EFCT` / `PARM` when read as big-endian char order). On-disk little-endian fourCC bytes are the reverse: **`TCFE` / `MRAP`** — matches plate comment.

---

## 6. Gaps / open (acceptable for accept-with-gaps)

1. Full product names / contracts for ~20 FUN_* callees (apply, bind, leave-scope, name intern).
2. Exact layout of `stoChunkReader` beyond `+0x4044` mode flag and EnterChunkScope side-effects on `local_104`/`local_100`.
3. Complete PARM wire layout (name encoding, count fields `local_114`/`local_84`/`local_74` product names).
4. `effEffect` object layout beyond byte at `param_1+1` (AlphaTest flag) and `*param_1` pass-through.
5. Plate commentary on vehicle tint shaders / effects.glm (not body-proven here).
6. Calling convention / stack cleanup not re-proven from exit epilogues this pass (decomp shows two formals).

**Verdict:** **accept-with-gaps** — outer EFCT/PARM protocol, version policy, type switch skeleton, AlphaTest special case, and return polarity are sealed for AutoCore asset-port mapping; do not treat FUN_* bodies or full object layout as sealed from this dual alone.

---

## Checklist (reviewer)

| Check | Result |
|---|---|
| Clean CF matches live decompile | **Pass** |
| Three-rep agreement | **Pass** (decomp ≡ force; p-code tags; string bytes) |
| Tag / version / return polarity | **Pass** |
| AlphaTestEnable special case | **Pass** |
| Callers counted (9 xrefs / 2 parents) | **Pass** |
| FUN_* callee catalog dualed | **Open** (OWN-ONLY; out of scope) |
| Runtime / bit-for-bit | **Open** |
| Verdict | **accept-with-gaps** |
