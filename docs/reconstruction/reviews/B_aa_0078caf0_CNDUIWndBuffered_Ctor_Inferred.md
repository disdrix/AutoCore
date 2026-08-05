# Review B (skeptical / adversarial): `aa_0078caf0` CNDUIWndBuffered_Ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0078caf0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W34-T) |
| **Counterpart** | `reviews/A_aa_0078caf0_CNDUIWndBuffered_Ctor_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra decompile + `read_memory_bytes` + RTTI + xrefs. **No** `disassemble_bytes`.

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Is shopveh / vehicle-list window class | **Falsified** — RTTI is **CNDUIWndBuffered**; `CWndVehicle` is a **subclass** that calls this then overwrites vtbl |
| 2 | Is free helper / not a ctor | **Falsified** — installs vtbl; SEH; returns this; matching dtor `0078ca80` |
| 3 | ECX thiscall entry | **Falsified** — entry loads this from stack; call sites push 3 dwords; `ret 12` |
| 4 | HostBase is the window itself | **Falsified** — separate `new(0x80)` stored at `+0x2A8`; EnsureAux ECX=that host |
| 5 | Size is 0x488 / 0x4CC (nearby news) | **Falsified** — direct sites use **0x4FC**; 0x488/0x4CC are other widgets in same parents |
| 6 | Same class as Palantir env / CVOGEnvironmentSector | **Falsified** — UI hierarchy `CNDUIWndBuffered` : `CNDUIWindow` : `gfxUIWindow` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| RTTI class name | **Confirmed** | Wrong UI type hierarchy |
| Ctor not method | **Confirmed** | Double-construct / skip base |
| Nested HostBase ownership | **Confirmed** | Leak / wrong ensure target |
| Full color/field product map | **Medium** residual | Incomplete UI default port |

---

## 3. Cross-check

```
raw 2026-07-23: 007b5dd0; vtbl a99f74; field bank; new(0x80)+007560d0 → [0xaa]; 00756320(1); return this
live 2026-07-29: identical CF
RTTI: COL 00ab8280 → 00afe4d0 ".?AVCNDUIWndBuffered@@"
base 007b5dd0 vtbl 00a960ac → ".?AVCNDUIWindow@@"
subclass after-call vtbls: CWndPortrait / CWndVehicle / CWndParticles
alloc: 68 FC 04 00 00 at 008ff45x / 008a9cbx / 008e6d6x
dtor 0078ca80: same vtbl; dtor HostBase at +0xaa
string residual: "failed to create buffer texture for buffered window"; gfxUIBufferedWindow.cpp path in binary
```

---

## 4. Surviving contract for AutoCore

```
CNDUIWndBuffered_Ctor(this, arg1, arg2):
  CNDUIWindow_Ctor(this, arg1)
  vtbl = CNDUIWndBuffered
  init defaults; this->flagAt_488 = arg2
  this->hostAt_2A8 = new HostBase(0x80) or null
  HostBase_EnsureAuxPtrs(host, 1)
  return this
```

Port as **UI base ctor** size **0x4FC**. Subclasses call then replace vtbl. Do **not** name from shopveh XML. Pair HostBase with W32-O/Q.

---

## 5. Open questions

- Product names for `arg1`/`arg2` and color bank rows.
- Whether EnsureAux on null host is intentional no-op/crash path (matches binary).

**Verdict:** **accept-with-gaps**
