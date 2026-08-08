# Review B (skeptical / adversarial): `aa_0054cc10` SkillStaging_ZeroPayloadFields_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0054cc10` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY R13-038 dual B) |
| **Counterpart** | `reviews/A_aa_0054cc10_SkillStaging_ZeroPayloadFields_Inferred.md` |
| **Dual start** | 2686 |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This leaf **is** PossessCreature DefaultFactory (`0x0054cbb0`) | **Falsified** — different body (`0x830` vs `0x53`); no `operator_new`; no vtbl store; zeros fields only |
| 2 | Allocates / constructs a skill HB object | **Falsified** — no CALL callees; pure stores of zero |
| 3 | Zeros whole object including header | **Falsified** — first mid store range starts at `+0x28`; `+0x00..+0x27` untouched here |
| 4 | Zeros past `+0x534` | **Falsified** — last store `+0x534` then `C3`; next fn `0x0054d440` |
| 5 | `__cdecl` with stack arg / `RET 4` | **Falsified** — bare `C3`; this via ECX only |
| 6 | Multiple direct CALL sites | **Falsified** — exactly 1 UNCONDITIONAL_CALL (`0x0054a2d1`) |
| 7 | DATA factory-slot reachability | **Falsified** — 0 DATA xrefs |
| 8 | Performs the full `0x14e` staging clear | **Falsified** — that is caller `REP STOSD`; this leaf only mid-range |
| 9 | Non-leaf (calls helpers) | **Falsified** — callees empty; classification leaf |
| 10 | Runtime Confirmed | **Fails** — Terminal false; no Launcher |
| 11 | Ghidra surface `undefined FUN_*(void)` means no ECX this | **Noise** — decompile + call-site `LEA ECX` seal thiscall |
| 12 | Scaffold name “CalleeOf no skill elements” is the product role | **Noise** — that string is the caller’s early-out log; this leaf runs only after the gate passes |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Zero `+0x28`..`+0x534` / `0x144` dwords | **High** | Wrong staging layout |
| thiscall / bare RET / void | **High** | Stack imbalance |
| Body `0x0054cc10`–`0x0054d43f` | **High** | Merge with next leaf |
| Sole CALL from install staging | **High** | Missed graph |
| Distinct from adjacent factory `0054cbb0` | **High** | Wrong lifecycle port |
| Role English “SkillStaging ZeroPayloadFields” | **Inferred** | Naming only |
| Per-field product semantics | **Open** | Documentation only |
| Why redundant vs post-call memset | **Open** | Dead-code suspicion only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes

```text
raw/live:
  for each dword slot in [self+0x28, self+0x534]:
    store 0
  return;   // bare C3

entry:
  0F 57 C0                 xorps xmm0, xmm0
  8B C1                    mov   eax, ecx
  F3 0F 11 40 2C           movss [eax+0x2c], xmm0
  F3 0F 11 40 30           movss [eax+0x30], xmm0
  33 C9                    xor   ecx, ecx
  89 48 28                 mov   [eax+0x28], ecx
  … (store cloud) …
  F3 0F 11 80 34 05 00 00  movss [eax+0x534], xmm0
  C3                       ret

call site (0054a2ca..):
  LEA ECX, [ESP+0x1a0]
  CALL 0054cc10
  XOR EAX, EAX
  MOV ECX, 0x14e
  LEA EDI, [ESP+0x1a0]
  REP STOSD
```

Clean **must not**:
- merge with `0x0054cbb0` factory or full skill ctor paths,
- claim full-object memset including header,
- claim multi CALL / DATA factory slot,
- invent Runtime Confirmed,
- dual the install parent (`0x0054a290`) or map helpers in this unit,
- claim non-zero stores or callees.

---

## 4. Surviving contract for AutoCore

```csharp
// Retail aa_0054cc10 — SkillStaging_ZeroPayloadFields_Inferred
// thiscall; ECX=self; bare ret; void.
// Zeros payload dwords [+0x28 .. +0x534] inclusive (0x144 dwords).
unsafe void ZeroPayloadFields(void* self)
{
    var p = (uint*)((byte*)self + 0x28);
    for (int i = 0; i < 0x144; i++)
        p[i] = 0;
}
// Not a substitute for full staging clear (0x14e dwords / 0x538 bytes) done by caller.
// Not PossessCreature DefaultFactory (0x0054cbb0).
```

**Port notes:** Keep as pure mid-field zero helper. Do not assume it clears the full skill-staging header. Preserve void thiscall ABI. Do not merge with skill HB construction factories.

---

## 5. Verdict

**accept-with-gaps** — adversarial checks leave CF/ABI/range/leaf/sole-caller intact and keep factory conflation falsified; remaining gaps are per-slot English, mid-vs-full clear rationale, and runtime confirmation.
