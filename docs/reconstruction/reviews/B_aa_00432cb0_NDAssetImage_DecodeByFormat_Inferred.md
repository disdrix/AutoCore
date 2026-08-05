# Review B (skeptical / adversarial): `aa_00432cb0` NDAssetImage_DecodeByFormat_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00432cb0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W22-P) |
| **Counterpart** | `reviews/A_aa_00432cb0_NDAssetImage_DecodeByFormat_Inferred.md` |
| **Verdict** | **accept-with-gaps** on dispatch/modes/string; residual mode-4 English + product name |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Pure thiscall; format is stack arg | **Falsified** — **EAX** is format formal (`TEST EAX` prologue; callers load EAX) |
| 2 | cdecl / bare RET | **Falsified** — **`RET 4`** |
| 3 | TGA-only loader | **Falsified** — modes cover BMP/PNG/other + auto cascade |
| 4 | Auto order is BMP-first | **Falsified** — **TGA → PNG → BMP → residual** |
| 5 | Failures throw C++ exceptions | **Falsified** — this unit returns **0** and stamps `context+0x44` (loaders may throw internally) |
| 6 | Success returns without commit | **Falsified** — always `FUN_00432580(param_2)` before return 1 (except early auto residual success which also commits) |
| 7 | Unknown modes silently return 1 | **Falsified** — `"Decode: Unknown or wrong format"` + return 0 |
| 8 | No stream rewinds in auto | **Falsified** — `vtbl+0x14` / `vtbl+0x10` between tries |
| 9 | Sole caller is LoadTGA | **Falsified** — this **calls** LoadTGA; callers are `FUN_00432be0` / `FUN_00432c50` |
| 10 | Decompile drifted | **Falsified** — live ≡ raw body |
| 11 | Clean reorders cascade | **Falsified** — scaffold preserves order |
| 12 | Mode-4 format is PNG | **Falsified** — PNG is mode 2 / `FUN_00435410`; mode 4 is `FUN_0098b5b0` residual |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| EAX mode + RET 4 + return polarity | **High** | Wrong caller ABI |
| Auto cascade order | **High** | Wrong asset type accepted first |
| TGA / PNG / BMP mapping | **High** (TGA dual; PNG plate; BMP sibling) | Mislabel formats |
| Unknown string + `+0x44` sink | **High** | Lost diagnostics |
| Stream rewind | **High** | Multi-try auto broken |
| Mode-4 English | **Tentative** | Wrong residual format story |
| `FUN_00432580` = commit/move | **Probable** | Wrong ownership of pixels |
| Product name | **Tentative** | Naming only |

---

## 3. Cross-check

```
Rep A — decompile_function(0x00432cb0):
  EAX modes 0..4; cascade; string; FUN_00432580; return 1|0

Rep B — read_memory entry + epilogues:
  55 8B EC 83 E4 F8 81 EC 74 03 00 00 85 C0 53 56 57 8B D9
  success B0 01 … C2 04 00; fail 32 C0 … C2 04 00

Rep C — xrefs + assembly_context:
  callers FUN_00432be0 @00432c16, FUN_00432c50 @00432c72
  both set EAX then CALL
```

**Attack on PNG/BMP labels:** PNG uses plate string on `FUN_00435410`; BMP linked via sealed `NDAssetImage_Flip` caller notes on `FUN_00433dc0`. **Accept as High structural / sibling-sealed; not re-dualed here (OWN VA only).**

**Attack on “auto always succeeds if file exists”:** mode 0 can still hit unknown string if all four loaders fail; forced modes copy loader error text from stack image. **Pass.**

---

## 4. Surviving contract

```
ok = DecodeByFormat(stream ECX, context, mode EAX):
  switch mode:
    0: pos=stream.tell()
       try TGA(stack_img, stream); if ok: break
       stream.seek(pos); try PNG; if ok: break
       stream.seek(pos); try BMP; if ok: break
       stream.seek(pos); try residual; if ok: commit; return 1
       context.error = "Decode: Unknown or wrong format"; return 0
    1: try BMP; fail → copy error; return 0
    2: try PNG; fail → copy error; return 0
    3: try TGA; fail → copy error; return 0
    4: try residual; fail → copy error; return 0
    else: context.error = "Decode: Unknown or wrong format"; return 0
  commit FUN_00432580(context); return 1
```

---

## 5. Gaps surviving attack

1. Product dispatcher name.
2. Mode-4 residual format English.
3. Dual of ctor/dtor/commit helpers.
4. Runtime golden assets per mode.

**Verdict:** **accept-with-gaps**
