# Review B (skeptical / adversarial): `aa_00970260` effEffect_Unserialize

| Field | Value |
|---|---|
| **Stable ID** | `aa_00970260` |
| **VA** | `0x00970260` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00970260_effEffect_Unserialize.md` |
| **Owner** | dual-w6-eff (OWN-ONLY this VA) |
| **Verdict** | **accept-with-gaps** — protocol skeleton sealed; plate extras and FUN_* semantics over-claimed if treated as complete codec |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Accepts any chunk tag | **Falsified** — hard compare `0x45464354` (EFCT); else invalid-TAG log |
| 2 | Accepts all versions including v1 | **Falsified** — v1 is explicit DX8 reject; only `2` and `3` enter body |
| 3 | Failure and success both return nonzero | **Falsified** — success after non-PARM peek returns **0**; errors return **`0xffffffff`** |
| 4 | Always consumes infinite PARMs | **Falsified** — loop exits on first non-`0x5041524d` tag |
| 5 | All bool params set AlphaTest | **Falsified** — only name `== "AlphaTestEnable"` **and** value nonzero |
| 6 | Plate vehicle-tint math runs in this function | **Falsified** — no tint/lerp ops in body; plate is domain commentary only |
| 7 | Type switch has only one float path | **Falsified** — type 3 branches on `local_84` 0/1/2/3 with unimplemented sink |
| 8 | Type 4 always same apply | **Falsified** — `strstr(name,"Phase")` forks `FUN_007522a0` vs `FUN_0043eea0` |
| 9 | Single caller | **Falsified** — 9 call sites: `gfxGeometryPiece_Unserialize`×2 + `FUN_0095ef50`×7 |
| 10 | Clean is production-ready types | **Overstated** — still `param_1`/`param_2`, FUN_*, SSO decomp noise |
| 11 | Decompile alone invents tags | **Falsified** — basic p-code carries consts `45464354` and `5041524d` |
| 12 | Force recompile changes CF | **Falsified** — `force_decompile` identical to first decompile |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| EFCT / PARM fourCC values | **Confirmed** | Wrong asset reader rejects all effects / loops forever |
| Version policy (reject 1; accept 2–3) | **Confirmed** | Load DX8 legacy or drop v3 effects |
| Success=0 / fail=-1 | **Confirmed** | Callers mis-handle geometry/effect attach |
| AlphaTestEnable → Alpha_Test + byte `effect+1` | **Confirmed** | Wrong alpha-test technique / flag |
| PARM types 1–5 skeleton | **Confirmed** | Mis-parse parameter stream |
| Exact PARM wire (counts, matrix size 16 claim) | **Medium** | Plate asserts matrix-16; type-3 body uses runtime counts — do not hardcode without samples |
| v2 vs v3 name load helpers | **High** | Wrong intern path for ISTR-only assets |
| `reader+0x4044` dual helpers | **High** gate exists | Mis-map stream vs buffer mode |
| FUN_* apply / bind semantics | **Low–Tentative** | Wrong GPU param upload if ported blindly |
| Vehicle tint / effects.glm plate text | **Not body-proven** | Confuse shader product with this loader |

---

## 3. Cross-check against three-rep

```
Rep A — decompile_function(0x00970260):
  EFCT/PARM tags; ver 1 reject / 2–3 accept; switch 1–5;
  AlphaTestEnable; success 0 / fail -1; plate strings

Rep B — force_decompile(0x00970260):
  identical pseudocode (no CF drift)

Rep C — read_memory + basic p-code:
  entry prolog SEH @ 0x00970260 (push -1, SEH LAB_009b261b, sub esp,0x128…)
  p-code const tags 0x45464354, 0x5041524d
  strings:
    0x00a9eba8 Invalid chunk version unserializing effEffect
    0x00a9ebd8 AlphaTestEnable
    0x00a9ebe8 DX8 geo files are not supported, please re-export
    0x00a9ec1c Invalid TAG unserializing effEffect
    0x00a9ec40 ...\graphics\Effects\effEffect.cpp
    adjacent Alpha_Test
  xrefs: 9 unconditional calls from 2 parent functions
```

**Attack on “plate is authoritative wire doc”:** plate’s PARM layout (name\0 + u32 type + typed payload) is **consistent** with the switch but **not fully re-derived** from this unit alone without dualing the read helpers. Treat plate as **high-quality annotation**, not independent runtime proof.

**Attack on fourCC spelling:** u32 `0x45464354` is **not** the on-disk byte order `TCFE`; both are correct depending on host vs file view — document both to avoid false “tag mismatch” bugs.

---

## 4. Surviving contract for AutoCore

```
// Asset / graphics effect load only — not combat/network.
// Own VA 0x00970260 only; do not invent callee bodies here.

uint32_t effEffect_Unserialize(EffEffect* effect, StoChunkReader* reader):
  require current chunk tag u32 == 0x45464354  // EFCT / file TCFE
  ver = current version
  if ver == 1: log DX8 unsupported; return 0xFFFFFFFF
  if ver != 2 && ver != 3: log invalid version; return 0xFFFFFFFF
  load effect name (v2 inline string path vs v3 FUN_0096a7f0 path)
  if resolve(name) < 0: return 0xFFFFFFFF
  while peek_tag() == 0x5041524D:  // PARM / file MRAP
    enter PARM; read name + valueType
    apply by type:
      1 bool  — if name AlphaTestEnable && val: enable Alpha_Test; effect.flag_byte_at_+4 = 1
      2 int
      3 float[] (multiple submodes; may allocate + readF32Array)
      4 string — Phase substring → alternate apply
      5 string/resource — bind fail → return 0xFFFFFFFF
  finalize remaining; return 0
```

### Caller contract (context only; not dualed)

| Parent | Sites | Role (from existing records) |
|---|---|---|
| `gfxGeometryPiece_Unserialize` `0x0074af60` | 2 | geometry piece embeds effect @ `this+0x1c` |
| `FUN_0095ef50` (body-massage / multi-effect) | 7 | repeated effect slots |

---

## 5. Residual uncertainty (honest)

| # | Item | Blocks seal of this unit? |
|---|---|---|
| R1 | FUN_* apply/bind/leave-scope product names | **No** for outer protocol; **Yes** for full port of param apply |
| R2 | Full `effEffect` object layout | **No** for loader control flow |
| R3 | Whether type-3 count==16 always means 4×4 matrix | **No** (plate claim; runtime count-driven) |
| R4 | Exact SSO / basic_string stack shapes | **No** for behavioral map |
| R5 | Runtime / sample EFCT blob differential | Open; does not invalidate static seal |

**Verdict:** **accept-with-gaps** — safe as **EFCT/PARM effect-unserialize behavioral map** for AutoCore; do not ship a full param codec or tint shader from this unit alone; do not expand ownership into callee VAs without separate duals.

---

## Checklist (adversarial)

| Check | Result |
|---|---|
| Over-claim plate tint math | **Rejected** |
| Tag endian confusion documented | **Pass** |
| Success/fail polarity inverted? | **No** — 0 vs -1 sealed |
| Three-rep stable | **Pass** |
| OWN-ONLY respected | **Pass** (no other VA duals / no ledgers) |
| Verdict | **accept-with-gaps** |
