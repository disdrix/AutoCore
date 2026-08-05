# Review B (skeptical / adversarial): `aa_00731130` PalToolNoMap_Host0x44_DualChannelInit_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00731130` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W36-J) |
| **Counterpart** | `reviews/A_aa_00731130_PalToolNoMap_Host0x44_DualChannelInit_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | ECX-thiscall method | **Falsified** — stack formal; `RET 4`; ECX temps only |
| 2 | Single material channel only | **Falsified** — explicit +0x34 then +0x3c ladders + `FUN_00730b50(...,0|1)` |
| 3 | Returns void / ignores status | **Falsified** — OR of many statuses into EAX |
| 4 | Scaffold name `Gfx_PalToolMaterialNoMap_00731130` sufficient | **Careful** — plate is real but omits dual-channel Host0x44 role; keep structural `_Inferred` name |
| 5 | Multiple static callers | **Falsified** — bulk xrefs: sole `0073c9ad` in `FUN_0073c810` |
| 6 | Host size unknown | **Mostly sealed** — caller `new(0x44)`; slots +0x34/+0x3c require span ≥ 0x40; bootstrap size 0x44 |
| 7 | Emissive always written like Diffuse | **Falsified** — channel0 emissive only updates when handle ≥ 0 (seed 0xFFFFFFFF) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| stdcall host* + RET 4 | **High** | Wrong ABI |
| Dual slots +0x34/+0x3c | **High** | Wrong layout |
| Plate effect/param strings | **High** | Wrong effect binding |
| OR-return semantics | **High** | Wrong error model |
| Product English | **Low** | Naming only |
| Unowned callee depth | **Open** | Incomplete port of helpers |
| Runtime | **Open** | Matrix |

---

## 3. Cross-check against raw + bytes + xrefs

- Full 718 B hex ends `5f5e0bc55d83c408c20400`.
- Prologue `83 EC 08 55 56 57` — frame + saved regs; stack host load `8B 7C 24 18`.
- Channel offsets: `83 C7 34` (+0x34) then later `83 C7 3C` (+0x3c).
- Xref: one unconditional call from `0073c9ad` (W35-E slot5).

---

## 4. Surviving contract for AutoCore

```
// Port as stdcall post-ctor dual-channel init (not thiscall):
uint32_t InitPalToolNoMapDual(void *host /* size 0x44 */) {
  // for ch in {0,1}:
  //   mat = host + (ch==0 ? 0x34 : 0x3c)
  //   bind PalToolMaterialNoMap.fx + MatDiffuse/Ambient/Specular/Emissive
  //   device helper; refcount-swap mat holder; BuildChannel(host, ch)
  // return OR of all statuses
}
// Do not invent product class English beyond plate string.
// Pair with HostPtrTable12 slot5 allocation + FUN_00457720 ctor (W35-E / W36-I).
```

---

## 5. Verdict

Adversarial pass confirms A on ABI, dual-channel ladder, strings, sole caller, OR-return. Residual product English + unowned helpers → **accept-with-gaps**.
