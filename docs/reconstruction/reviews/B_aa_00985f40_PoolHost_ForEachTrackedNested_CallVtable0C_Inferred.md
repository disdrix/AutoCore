# Review B (skeptical / adversarial): `aa_00985f40` PoolHost_ForEachTrackedNested_CallVtable0C_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00985f40` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (OWN-ONLY W38-AD) |
| **Counterpart** | `reviews/A_aa_00985f40_PoolHost_ForEachTrackedNested_CallVtable0C_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | `in_EAX` is phantom / unused | **Falsified** — entry `8B 58 04` / `8B 68 08` load host+4/+8 from EAX; caller preloads EAX from device+0x73C |
| 2 | Virtual call is cdecl with no this | **Falsified** — `8B 0E; 8B 01; FF 50 0C` sets ECX=obj before CALL [vtbl+0xC] |
| 3 | Function is IB/VB factory tree walk | **Falsified** — no tree/sentinel; flat ptr vectors; no FUN_00743c50/7465c0 |
| 4 | Multiple callers | **Falsified** — single xref `0x0075f0d1` |
| 5 | Host is GfxDevice this (full 0x7b0) | **Falsified** — parent moves `EAX=[device+0x73C]` (subsystem pointer slot) |
| 6 | Empty inner only checks null | **Falsified** — also SAR count `((end-begin)>>2)==0` before inner loop |
| 7 | Scaffold gfxDevice demangle is product name | **Rejected** — string path is parent file only; keep `_Inferred` structural |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| EAX host + bare C3 | **High** | Wrong ABI port |
| Double vector structure | **High** | Missed nested objects |
| thiscall vtbl+0xC | **High** | Wrong call convention |
| Device Reset ordering | **High** | Wrong shutdown phase |
| Slot = PoolHost track host | **High** (layout + ctor seed) | Wrong host type |
| vtbl+0xC English | **Low** | Naming only |
| Container product type | **Med** | Wrong nested model |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + caller

```
// FUN_0075eff0 @ 0x0075f0c8..:
//   MOV EAX, [EBP+0x73C]
//   ADD ESP, 0x10          ; clean log args
//   CALL 0x00985f40
// Entry: 51 53 8B 58 04 55 8B 68 08 3B DD 74 3A ...
// Exit:  5F 5E 5D 5B 59 C3 @ 0x00985f8a
// GfxDevice ctor (W35-R): +0x73C size 0x20 → DAT_00d1f624 PoolHost seed
```

Live decompile 2026-08-04 ≡ raw 2026-07-23 skeleton; bytes seal thiscall ECX.

---

## 4. Surviving contract for AutoCore

```
// Port as pre-reset notify walk (not COM Release factory):
//   host = device.poolHost; // +0x73C / *DAT_00d1f624
//   for each tracked container in host.track[+4,+8):
//     for each obj* in container.vec[+8,+0xC):
//       obj->vtbl[3](); // +0xC thiscall
// Retail: EAX=host; no stack args; void.
// Do not invent vtbl method English; keep _Inferred.
// Do not merge with IB/VB tree PreResetReleaseAll.
```

---

## 5. Verdict

Adversarial pass confirms A on EAX ABI, double-vector walk, thiscall vtbl+0xC, sole Device Reset site. Residual product English for method/container → **accept-with-gaps**.
