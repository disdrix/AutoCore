# Review B (skeptical / adversarial): `aa_007543b0` Palantir_BaseCtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_007543b0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W35-I) |
| **Counterpart** | `reviews/A_aa_007543b0_Palantir_BaseCtor.md` |
| **Scratch** | `tmp/a_007543b0.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | ECX-thiscall ctor | **Falsified** — `MOV ESI,[esp+0x18]`; `RET 4`; no ECX load of self |
| 2 | Allocates Palantir with `operator_new` | **Falsified** — placement only; returns passed-in self |
| 3 | Is the sole full client host ctor | **Falsified** — sole caller `FUN_007a26c0` replaces vtbl with `PTR_FUN_00a97170` and adds large tail |
| 4 | Decompiler void/no-arg signature is complete | **Falsified** — stack formal + EAX return + RET 4 |
| 5 | Class is AssManager-only (not Palantir) | **Falsified** — same vtbl as W34-K `Palantir_CompleteDtor` / ResetDevice peer |
| 6 | Does not publish globals | **Falsified** — writes `DAT_00d1f058` and `DAT_00d1f1fc` (nested also `DAT_00d1f050`) |
| 7 | Nested `FUN_0075d470` sealed in this dual | **Accepted gap** — unowned |
| 8 | Scaffold Client_InitInstance chain name is product | **Falsified** — structural auto-name only; reject |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Stack-self + RET 4 + EAX=self | **High** | wrong calling convention in port |
| Global publishes | **High** | stale/missing singleton |
| Nested at `+0x30` / shell `+0xA0` / string `+0xB4` | **High** | layout mismatch vs dtor |
| Product class Palantir | **High** | wrong subsystem |
| Nested cache ctor internals | **Low** | incomplete member init port |
| Runtime | **Open** | matrix |

---

## 3. Cross-check against raw + bytes + pair dtor

```
// FUN_007543b0 (bytes)  ↔  FUN_00754320 (W34-K complete dtor)
vtbl 00a9f76c          ↔  vtbl 00a9f76c (dtor phase)
DAT_00d1f058 = self    ↔  DAT_00d1f058 = 0
FUN_0075d470(+0x30)    ↔  FUN_0075d8e0(+0x30)
DAT_00d1f1fc = +0xA0   ↔  tidy +0xA0; DAT_00d1f1fc = 0
string(+0xB4, ".")     ↔  ~string(+0xB4)

// FUN_007a26c0
CALL FUN_007543b0(self)
*self = PTR_FUN_00a97170   // derived vtbl overwrite
```

Ctor/dtor stage symmetry holds for owned offsets; `+0x10` subobject still only appears on dtor side → residual gap, not a falsification of this ctor plate.

---

## 4. Surviving contract for AutoCore

```
// Port as placement base ctor (not factory):
Palantir* Palantir_BaseCtor(Palantir* self /*stack; RET 4*/) {
  DAT_00d1f058 = self;
  self->vtbl = &Palantir_Vtbl_00a9f76c;
  // flags + copy DAT_00d1f01c/020; zero +0x14..+0x20
  CoInitializeEx(nullptr, COINIT_APARTMENTTHREADED);
  // +0x24=-1; zero +0x28/+0x2C
  NDResourceCache_Ctor(self+0x30);       // FUN_0075d470
  DAT_00d1f1fc = self+0xA0; zero triad;
  basic_string_ctor(self+0xB4, ".");
  // +0xD0=1; +0xD1=0; +0xD4=0
  return self;
}
// Do not treat as ECX-thiscall.
// Do not skip either global publish.
// Extended host ctor (FUN_007a26c0) may replace vtbl after return.
```

---

## 5. Verdict

Adversarial checks strengthen stack ABI + Palantir identity + global/layout seal; nested ctor dual and `+0x10` residual remain → **accept-with-gaps**.
