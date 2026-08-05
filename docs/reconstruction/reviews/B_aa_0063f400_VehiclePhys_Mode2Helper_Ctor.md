# Review B (skeptical / adversarial): `aa_0063f400` VehiclePhys_Mode2Helper_Ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_0063f400` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W25-K) |
| **Counterpart** | `reviews/A_aa_0063f400_VehiclePhys_Mode2Helper_Ctor.md` |
| **Scratch** | `tmp/a_0063f400.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Analyze meta `undefined (void)` is ABI | **Falsified** — `RET 4`, ECX this, stack host, EAX return |
| 2 | Shared with mode-1 singleton | **Falsified** — mode-1 is static `PTR_PTR_00af4f88`; this is heap 0x60 + distinct vtable |
| 3 | Multiple callers | **Falsified** — sole xref `005d4094` in SetModeHelper mode-2 |
| 4 | Name is product-sealed | **Overstated** — **Inferred** from caller; no string on VA |
| 5 | g_fl* names imply kill-cam semantics on vehicle phys | **Noted residual** — Ghidra symbols reused; vehicle English open |
| 6 | Zero-then-write of +0x2c/+0x4c is decompiler noise | **Falsified as noise** — bytes do xorps zero then movss 1.0 (write-after-clear) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ABI thiscall RET4 | **High** | Stack smash / wrong this |
| Sole mode-2 caller | **High** | Wrong install path |
| Vtable / refcount | **High** | COM lifetime bug |
| Float constant values | **High** | Wrong defaults |
| Product field English | **Low–Med** | Misleading port comments |
| Nested 0063f330 | **Medium** | Wrong +8 seed |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes

```
this = ECX; host = [esp+4]
self[+0x50..+0x5c] = {0.01, 0.005, 0.1, 0.2}
*(u16*)(this+6) = 1
*this = PTR_FUN_009e3ec0
[+0x10..],[+0x30..] = FLT_MAX×4
[+0x20..] zero + 1.0; [+0x40..] zero + 1.0
FUN_0063f330(this, *(host+0xc))
return this; RET 4
```

Live decompile 2026-07-29 ≡ raw 2026-07-23 CF. Caller allocates 0x60 before entry.

---

## 4. Surviving contract for AutoCore

```
// Mode-2 phys helper ctor (client vehicle stack)
helper = factory_alloc(0x60);
VehiclePhys_Mode2Helper_Ctor(helper, physHost);
// install at physHost+0x54 with AddRef/Release dance in SetModeHelper
// Do not confuse with mode-1 static singleton
```
