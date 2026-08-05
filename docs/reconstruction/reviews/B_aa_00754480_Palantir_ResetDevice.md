# Review B (skeptical / adversarial): `aa_00754480` Palantir_ResetDevice

| Field | Value |
|---|---|
| **Stable ID** | `aa_00754480` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W35-K) |
| **Counterpart** | `reviews/A_aa_00754480_Palantir_ResetDevice.md` |
| **Scratch** | `tmp/a_00754480.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is a dtor / complete-dtor peer body | **Falsified** — no vtbl install, no member destroys; returns status; Sleep on fail |
| 2 | Name is only scaffold `Named_Palantir` | **Falsified** — log string is exact `"Palantir::ResetDevice failed..."` |
| 3 | Void return | **Falsified** — success `XOR EAX,EAX`; fail `OR EAX,0xFFFFFFFF` |
| 4 | Nested call is simple 3-arg cdecl only | **Weakened** — bytes also set **EAX=this+8** before `FUN_0075eff0` (device subobject) |
| 5 | `+6` is unrelated status | **Falsified** — set 1 on fail, 0 on success; matches retry messaging |
| 6 | Sleep is not 1000 ms | **Falsified** — push `0x3E8` then IAT Sleep |
| 7 | Only vtbl-dispatched | **Falsified** — also direct CALL from `FUN_007a3c80` |
| 8 | Success path frees device | **Falsified** — only virtual notify on `*(this+0x2C)` with `this+8` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Product method name | **High** | wrong plate |
| ECX=this + bare RET + 0/-1 | **High** | ABI crash |
| retry flag + Sleep(1000) | **High** | wrong recovery policy |
| nested `FUN_0075eff0` ownership | **n/a** | intentionally open |
| `*(+0x2C)` class English | **Low** | notify side effects |
| Runtime | **Open** | matrix |

---

## 3. Cross-check against raw + bytes + callers

```
// FUN_00754480 (bytes)
ESI=ECX; EDI=ESI+8
hr = FUN_0075eff0(EAX=EDI, stack [+0x28],[+0xB0],byte[+5])
if hr<0: log ResetDevice failed; [+6]=1; Sleep(1000); return -1
[+6]=0; (*(+0x2C))->vtbl[+8](EDI); return 0

// FUN_007a3c80
CALL FUN_00754480; if EAX==0: SendNotifyMessageA(HWND_BROADCAST,0x801B,0,0); [this+0x12C]=1

// Vtbl PTR_FUN_00a9f76c
[0]=scalar dtor FUN_004447e0; [1]=FUN_00754480
```

String memory at `0x00a9f85c` seals product method name independent of Ghidra symbol.

---

## 4. Surviving contract for AutoCore

```
// Port as Palantir::ResetDevice:
int Palantir_ResetDevice(Palantir* self) {
  int hr = GfxDevice_Reset(/* from self+0x28 / self+8 / ... */); // unowned plate
  if (hr < 0) {
    Log(Palantir.cpp, 0x184, "Palantir::ResetDevice failed. Will try again in 1000 msec. ");
    self->reset_retry = 1;
    Sleep(1000);
    return -1;
  }
  self->reset_retry = 0;
  NotifySubobject(self->field_2C, self+8); // vtbl+8
  return 0;
}
// Do not treat as dtor. Do not skip Sleep/retry flag on failure.
// Do not invent full gfxDevice Reset here — nested dual.
```

---

## 5. Verdict

Adversarial pass confirms product ResetDevice, ABI, and fail/success arms. Nested device + subobject English open → **accept-with-gaps**.
