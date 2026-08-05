# Review B (skeptical / adversarial): `aa_0074af60` gfxGeometryPiece_Unserialize

| Field | Value |
|---|---|
| **Stable ID** | `aa_0074af60` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY dual A/B create) |
| **Counterpart** | `reviews/A_aa_0074af60_gfxGeometryPiece_Unserialize.md` |
| **System** | `graphics / gfx` (asset I/O — GPCE chunk) |
| **Dual status** | **Present** (A + B modern pair) |
| **Verdict** | **accept-with-gaps** on tag/version/CF/offsets; **needs-more-evidence** on soft-skip English, `local_98==2`, string-slot names, runtime |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Always unserializes current assets (v10 only) | **Overstated** — body still accepts **v8 and v9**; only Serialize **writes v10** |
| 2 | Soft path `FUN_00767120` → 0 is a hard error | **Falsified** — returns **0**, not −1; distinct from tag/version fail |
| 3 | Tag is ASCII `"GPCE"` in memory as G-P-C-E | **Clarify** — imm is `0x47504345`; file order is **ECPG** (`45 43 50 47`); fourCC name GPCE is plate convention |
| 4 | `param_1` is full object like Serialize | **Falsified (layout)** — vtbl at `param_1-4`; Serialize indices map with **+4** this-adjust |
| 5 | v8/v9 always write vertex into `+0xc` | **Falsified** — when `local_98 == 2`, dual stack objects + merge helpers; only else-branch is direct `FUN_009a0000(+0xc)` |
| 6 | Success always returns 0 | **Partially false** — success maps `*(reader+0x402c)`: ≥0 → **0**, else **−1** (reader error after “happy” path) |
| 7 | Effect/index failures are ignored | **Falsified** — both checked `< 0` → `LAB_0074b044` return **−1** |
| 8 | Disk tail “ADSU / LODLevel” is proven by immediates in this body | **Overstated** — plate/Serialize commentary; this body shows string reads + `FUN_007496c0` without embedding `"LODLevel"` imm here |
| 9 | Clean invents control flow | **Survives as false** — clean ≡ raw ≡ live decomp |
| 10 | Only one caller | **Falsified** — 3 xrefs: morphed×2 + skinned×1 |
| 11 | `unaff_EBX` store at `+0x70` is garbage | **Residual** — decompiler failed to track return of `FUN_00436900`; store is real, source register tracking weak |
| 12 | Name “Unserialize” seals full piece graph | **Name OK** — body is one GPCE piece; parent GBOD/morph/skin own graph |

---

## 2. Decisive dataflow

```
gfxGeometryPiece_Unserialize(this_adj /* ECX = piece+4 */, reader) -> int
  scope = EnterChunkScope(reader)   // tag, version, okFlag
  if scope.tag != 0x47504345:
    log Invalid TAG (...:0xd6); leave; return -1
  if FUN_00767120() != 0:
    leave; return 0                 // NOT -1
  switch scope.version:
    10: flags; effect(+0x1c); index(+4); vertex(+0xc); post; names → ok
    9:  flags prelude; // fallthrough
    8:  effect; index; if mode==2 dual-temp verts else vertex(+0xc); post; names → ok
    default: log Invalid version (...:0x164); return -1
  on ok:
    return (reader.status_at_+0x402c >= 0) ? 0 : -1
  on effect/index fail: return -1

Callers (Ghidra 2026-07-29):
  FUN_00739c80 @ 0x00739d5f, 0x00739e3e   // morphed
  FUN_009991b0 @ 0x0099927e               // skinned
```

### Memory anchor

| VA | Bytes / sense |
|---|---|
| `0x0074af9b` | `81 7C 24 1C 45 43 50 47` — `CMP dword [esp+0x1c], 0x47504345` |

### Return residual (easy to mis-port)

| Path | Return | Risk if wrong |
|---|---|---|
| Bad tag / bad version / effect or index `< 0` | **−1** | Treat as success → corrupt mesh |
| `FUN_00767120` hit | **0** | Treat as fail → skip valid empty/skip cases |
| Happy path, reader status ≥ 0 | **0** | OK |
| Happy path, reader status `< 0` | **−1** | Ignoring `+0x402c` → false success |

---

## 3. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| GPCE tag imm + log lines | **High** | Wrong chunk accepted |
| Version set {8,9,10} | **High** | Reject legal old assets or accept garbage |
| Effect / index / vertex order (v10) | **High** | Buffer swap / crash |
| `local_98 == 2` dual-temp branch exists | **High** | Missing legacy path |
| Dual-temp **product** meaning | **Low** | Wrong modern port of v8/v9 |
| this+4 vs Serialize full this | **High** | Off-by-4 field map in AutoCore |
| Stores `+0x54/+0x8c/+0x90` | **High** | — |
| English bodyName/pieceName/LOD | **Probable** plate | Misnamed APIs only |
| Soft-skip `FUN_00767120` | **High** CF / **Low** English | Wrong skip policy |
| `reader+0x402c` status map | **High** | Silent false success |
| Vtbl `+0x78` / `+100` | **Tentative** names | Wrong virtual hook |
| Clean CF ≡ raw | **High** | — |
| Runtime asset proof | **None** | Format drift unknown |

---

## 4. Cross-check against Serialize twin

| Serialize (`0x0074ac40`) | Unserialize (this) | Adversarial note |
|---|---|---|
| `BeginChunk(0x47504345, 10)` | Accepts 8/9/**10** | Write is v10-only; read is backward-compatible |
| Effect serialize on `this+0x20` | `effEffect_Unserialize(this_adj+0x1c)` | +4 adjust holds |
| Index / vertex optional nulls | Always attempts unserialize helpers | Read path not symmetric on null skips |
| Flag bit `*(this+0xbc) & 1` write side | Read: `+0x50` char → clear or `+0xb8 \|= 1` | Same flag family; gate field `+0x50` not re-named |
| Three string slots | Three `FUN_00439a20` + hash stores | Order sealed; labels plate-level |

Do **not** claim read path is inverse of write path instruction-for-instruction — v8/v9 dual-temp and soft-skip have no Serialize twin in the write body.

---

## 5. Surviving contract for AutoCore

```
gfxGeometryPiece_Unserialize(pieceThisPlus4, stoChunkReader) -> int
  require current chunk tag GPCE (0x47504345 / file ECPG)
  soft-skip helper may return 0 without filling
  versions 8, 9, 10 only; else -1
  always: unserialize effect at +0x1c, index at +4
  v10: vertex at +0xc directly
  v8/v9: if mode dword == 2 then dual-temp vertex path else vertex at +0xc
  post hooks + three string/hash fields (+0x54, +0x8c, +0x90) + flag bit at +0xb8
  return 0 on success (reader status ok) or soft-skip; -1 on hard errors
  convention: __thiscall; piece pointer is Serialize(this)+4
```

**Porting rules (adversarial):**

1. Do **not** drop v8/v9 support if legacy GBOD assets still ship.
2. Do **not** collapse soft-skip (0) with hard fail (−1).
3. Keep this-adjust when sharing layouts with Serialize / morph / skin callers.
4. Do not invent ADSU parsing here without proving key literals or dualing `FUN_007496c0`.
5. Treat `FUN_009a00d0` / `FUN_009a0000` as INDX/VERT-class unserializers by pairing with Serialize — rename only after those duals seal names.

---

## 6. Verdict

**accept-with-gaps** on sealed CF, tag, versions, offsets, returns, and caller set.

**needs-more-evidence** before Confirmed: soft-skip English, `local_98==2` meaning, string field product names, vtbl slot names, live GPCE load.
