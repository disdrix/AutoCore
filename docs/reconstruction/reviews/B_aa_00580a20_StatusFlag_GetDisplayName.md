# Review B (skeptical / adversarial): `aa_00580a20` StatusFlag_GetDisplayName

| Field | Value |
|---|---|
| **Stable ID** | `aa_00580a20` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00580a20_StatusFlag_GetDisplayName.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Unit is “Weapons Disabled” only | Thirteen product returns + default; `"Weapons Disabled"` is case `0x10` alone | **Falsified exclusive name** |
| 2 | thiscall / ECX object | Prologue `mov eax,[esp+4]`; plain `C3` | **Stack arg leaf** |
| 3 | Dense enum 0..N sequential | Keys are sparse power-of-two; switch only covers low powers after range gate | **Sparse flag keys** |
| 4 | Bit mask at call site always equals key | Cast-block bit `8` → key `2` | **Caller remaps; unit pure** |
| 5 | Default never hit | Mid-band holes and multi-bit OR fall to default | **Default live** |
| 6 | Second arg from decomp call sites (`0xffffffff`) is formal | Body only reads one stack arg; second is `FUN_007a6de0` residual in caller decompile | **Single formal sealed** |
| 7 | Clean reordering of if/switch changes behavior | Integer exact-match set identical | **CF equivalent** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ABI + RET | **Confirmed** | Wrong port convention |
| String table completeness | **Confirmed** | Missing toast text |
| Default string | **Confirmed** | Wrong fallback UX |
| Canonical name | **Probable** | Doc only |
| Full product flag inventory | **Probable** | Dead keys undocumented |

---

## 3. Cross-check against raw / bytes

```
raw 2026-07-23 ≡ live decompile 2026-07-29 ≡ clean StatusFlag_GetDisplayName.cpp
entry: 8B 44 24 04  83 F8 40  ...
exit:  C3 @ 0x00580ac0
jump table @ 0x00580ac4; index bytes @ 0x00580ae0
string immediates point into 0x009d44c8.. pool (Speeding/Zombied/.../Stunned)
no CALL instructions in body
```

Reject ports that:

- Treat unit as Weapons-Disabled constant.
- Assume dense 0..12 enum indices.
- Require ECX/this.
- Drop the default fallback.

---

## 4. Surviving contract for AutoCore

```
// Client status flag display name (UI / cast-block)
const char* StatusFlag_GetDisplayName(int flagKey):
  switch/range exact-match power-of-two keys → English literals above
  else → "in a world of hurt"

// Server does not need this leaf for wire correctness.
// Do not confuse flag KEY with status BYTE bit positions — callers may remap.
```

---

## 5. Open questions

1. Are unlisted mid-band powers obsolete content?
2. Any non-power-of-two intentional keys?
3. Localization: are these raw English always passed through `FUN_007a6de0`?

**Verdict:** **accept** — adversarial kills Weapons-Disabled-only and thiscall misreads; sealed leaf stands.
