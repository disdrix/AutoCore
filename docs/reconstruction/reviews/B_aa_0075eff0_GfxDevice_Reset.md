# Review B (skeptical / adversarial): `aa_0075eff0` GfxDevice_Reset

| Field | Value |
|---|---|
| **Stable ID** | `aa_0075eff0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (OWN-ONLY W37-N) |
| **Counterpart** | `reviews/A_aa_0075eff0_GfxDevice_Reset.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is only a log helper | **Falsified** — full Reset shutdown/rebuild; D3D vcall + factory chain |
| 2 | cdecl 3-arg only (no EAX) | **Falsified** — caller sets **EAX=Palantir+8**; entry `MOV EBX,EAX`; used for present seed |
| 3 | Void / ignored return | **Falsified** — parent tests `EAX < 0`; success `XOR EAX,EAX`; fails return −1 |
| 4 | Bare RET / thiscall | **Falsified** — **`RET 12`** stdcall |
| 5 | Name must stay scaffold `Named_gfxDevice` | **Falsified** — path + `Device Reset()` strings seal **`GfxDevice_Reset`** |
| 6 | Multiple independent callers | **Falsified** — sole xref from `Palantir_ResetDevice` |
| 7 | Success path always restores accounting with live dims | **Weakened** — decompile shows zeroed temps on some rebuild multiplies; do not overclaim bit-exact accounting without runtime |
| 8 | vtbl+0x40 is not Reset | **Falsified** — HRESULT map strings explicitly mention `pd3dDevice->Reset()` / `IDirect3DDevice9::Reset()` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Product Reset plate | **High** | wrong subsystem |
| EAX + RET 12 + 0/−1 | **High** | ABI crash / wrong parent handling |
| Factory fail messages | **High** | mis-ordered rebuild |
| PresentParams field English | **Medium** | wrong present overlay |
| Accounting reverse math | **Low–Med** | telemetry only |
| Runtime | **Open** | matrix |

---

## 3. Cross-check against raw + bytes + callers

```
// Palantir_ResetDevice (W35-K bytes)
EAX = this+8
PUSH byte[this+5], [this+0xB0], [this+0x28]
CALL GfxDevice_Reset
if EAX < 0: log Palantir::ResetDevice failed; Sleep(1000); return -1
else notify *(this+0x2C); return 0

// GfxDevice_Reset
shutdown → IDirect3DDevice9::Reset → factories → caps → complete | -1
```

Closes W35-K residual “nested FUN_0075eff0 dual open”.

---

## 4. Surviving contract for AutoCore

```
// Port as gfxDevice Device Reset (nested from Palantir::ResetDevice):
// ABI: EAX=present_seed (Palantir+8); stdcall(device*, arg_b0, flag5); RET 12; return 0|-1
int GfxDevice_Reset(GfxDevice* device, uint32_t arg_b0, uint8_t flag5) {
  // tear down resources/factories
  // hr = device->d3d->Reset(&present_from_device_and_seed)
  // if failed: map D3D errors; TestCooperativeLevel; return -1
  // rebuild factories (IB/VB/Tex/Views/Effect/Stats/GlobalEffect); caps; surfaces; globals
  // return 0
}
// Do not invent Palantir retry/Sleep here — that stays in Palantir_ResetDevice.
// Do not drop EAX present seed.
```

---

## 5. Verdict

**accept-with-gaps** — product + ABI + Reset pipeline sealed; helper field English and runtime open.
