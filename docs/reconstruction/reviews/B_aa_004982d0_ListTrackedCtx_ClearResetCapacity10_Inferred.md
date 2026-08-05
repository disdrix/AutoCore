# Review B (skeptical / adversarial): `aa_004982d0` ListTrackedCtx_ClearResetCapacity10_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004982d0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (OWN-ONLY W37-AD) |
| **Counterpart** | `reviews/A_aa_004982d0_ListTrackedCtx_ClearResetCapacity10_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Ghidra `__fastcall` / `param_1` means ECX is a free integer, not this | **Partially softened** — Ghidra labels `__fastcall` but bytes are classic thiscall save (`MOV ESI,ECX`); sole caller loads object pointer into ECX |
| 2 | This is an NDRiver.fx loader step (scaffold Drive name) | **Falsified** — no FX strings here; only clear + store 10; FX load is later in caller `0048fc90` after return |
| 3 | Capacity store happens before clear | **Falsified** — CALL clear first; clear zeros +0xC; then `MOV [ESI+0xC],10` |
| 4 | Return is full EAX=1 | **Softened** — only `MOV AL,1`; high bytes of EAX are whatever clear left (clear also returns AL=1, so often 1, but contract is AL) |
| 5 | Self is the PalantirEnv root (ESI in caller) | **Falsified** — caller `MOV ECX,[ESI+0x100]` before call |
| 6 | This recomputes grid dims like sibling 004982f0 | **Falsified** — 19 B body has only clear + capacity; no map-scale math / `FUN_007874b0` |
| 7 | Multiple xrefs | **Falsified** — single xref `0048fe6d` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Clear-then-capacity-10 role | **High** | Wrong init order |
| Thiscall + AL=1 | **High** | ABI break |
| Self = env+0x100 ctx | **High** | Wrong object |
| ListTrackedCtx type link | **High** | Orphan wrapper |
| Capacity English (=10 meaning) | **Low** | Mis-size bank |
| Dim leave-zero intent | **Med** | Missing re-init |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + callers

```
// Entry: 56 8B F1 E8 A8 F9 FF FF C7 46 0C 0A 00 00 00 B0 01 5E C3
// CALL rel: 004982d8 + (-0x658) = 00497c80  (W33-R clear)
// Caller 0048fc90 @ 0048fe67: MOV ECX,[ESI+0x100]; CALL 004982d0
// Then caller continues NDRiver.fx path — not part of this unit
// Sibling 004982f0: same clear + capacity 10 + dim recompute (not this VA)
```

Live decompile 2026-08-04 ≡ raw 2026-07-23; body hex seals ordering and constant.

---

## 4. Surviving contract for AutoCore

```
// Port as ListTrackedCtx method:
ok = ListTrackedCtx_ClearResetCapacity10(ctx); // ECX=ctx at env+0x100
// Must: run full clear-destroy-reset, then *(ctx+0xC)=10, return 1.
// Do not recompute +4/+8 dims here (use 004982f0 sibling if needed).
// Do not free ctx itself.
// Do not treat as FX/string loader.
// Capacity constant is literal 10 (not read from config in this body).
```

---

## 5. Verdict

Adversarial pass confirms A on composition, ABI, sole caller, and non-FX role. Residual capacity product English + dim-leave intent → **accept-with-gaps**.
