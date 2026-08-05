# Review B (skeptical / adversarial): `aa_0099f450` Gfx_PalDiffMapFx_BindAndInitMesh_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0099f450` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W36-I) |
| **Counterpart** | `reviews/A_aa_0099f450_Gfx_PalDiffMapFx_BindAndInitMesh_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Ghidra `undefined FUN_0099f450(void)` is correct ABI | **Falsified** — stack loads + **`RET 8`**; two stack formals |
| 2 | `in_EAX` is decompiler noise only | **Partially falsified** — `MOV EBX,EAX` + gated path; sole caller zeros it deliberately (`33 C0` before call) |
| 3 | Function is ECX-thiscall method of host | **Falsified** — host is stack arg; material is `host+0x20`; no ECX=host prologue |
| 4 | Scale arg is ignored / always 10.0f inside body | **Falsified** — body reloads stack scale into `0099f270`; 10.0f is caller choice |
| 5 | Mat* set writes product-colored values from host fields | **Falsified** — EAX forced to static float4s white/blackA1 |
| 6 | `FUN_0073d940` always replaces material | **Falsified** — null check; only swap when non-null |
| 7 | Name should be bare `Gfx_PalDiffMap` | **Rejected as insufficient** — body is bind+params+mesh, not effect file alone; `_Inferred` BindAndInitMesh role required |
| 8 | Multiple external callers | **Falsified** — 1 xref / 1 caller (`0073c810`) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| stdcall RET 8 + 2 stack args | **High** | Wrong port ABI |
| mat @ +0x20 + four Mat* names | **High** | Wrong material wiring |
| float4 constants | **High** | Wrong default look |
| mesh tail `0099f270` + EDI host | **High** | Lost mesh init |
| Optional EAX path existence | **High** | — |
| Optional EAX product meaning | **Low** | Naming only at sole caller |
| Nested callee contracts | **Low** | Port stubs incomplete |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + callers

```
// Epilogue @ end of 0x0099f450 body:
// 5F 5E 0B C5 5D 5B 83 C4 14 C2 08 00
// POP EDI; POP ESI; OR EAX,EBP; POP EBP; POP EBX; ADD ESP,14; RET 8

// Sole call site 0x0073ca84 region:
// 68 00 00 20 41    PUSH 0x41200000   ; 10.0f
// 56                PUSH ESI          ; host*
// 33 C0             XOR EAX, EAX      ; optional formal 0
// 89 77 20          MOV [EDI+0x20],ESI ; table[8]=host (slot store near call)
// E8 ...            CALL FUN_0099f450

// Float4s:
// 00afdf40: 1,1,1,1
// 00afdf30: 0,0,0,1
// 00a9ede4: "DiffuseTexture"
```

Live decompile 2026-07-29 ≡ raw 2026-07-23 CF. Full-body hex seals RET 8 and param ladder.

---

## 4. Surviving contract for AutoCore

```
// Port as stdcall host init (NOT ECX thiscall):
uint32_t BindAndInit(void* host, float scale /*bits*/) {
  // lookup PalDiffMap.fx → bind into *(host+0x20)
  // set MatAmbient/Diffuse from white4; Specular/Emissive from (0,0,0,1)
  // optional DiffuseTexture if third EAX formal non-null (bootstrap passes 0)
  // maybe replace material with derived (refcount)
  // InitMesh(host, scale, 1.0f)
  // return OR of status codes (0 / -1 family)
}
// Do NOT invent product class English for dual-vtbl host.
// Do NOT treat as pure string table or effect compiler.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI, CF, strings, constants, sole caller. Residuals are product English + unowned nested duals + optional-EAX meaning → **accept-with-gaps**.
