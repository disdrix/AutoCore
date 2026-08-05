# Review B (skeptical / adversarial): `aa_00637da0` CVOGObjectiveRequirement_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00637da0` |
| **VA** | `0x00637da0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00637da0_CVOGObjectiveRequirement_ctor.md` |
| **Agent** | W17-Q OWN-ONLY |
| **Verdict** | **accept-with-gaps** on base ctor; falsify Collect/Deliver conflation |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | This is Collect ctor | Collect is `0x00611690` (type=2, vtable `009e12c4`, size 0x68) | **Falsified** |
| 2 | This is Deliver ctor | Deliver is `0x00610bc0` (type=3) | **Falsified** |
| 3 | Body sets RequirementType | No store to `+0x0c`; only vfptr + parent | **Falsified** |
| 4 | Vtable stays as final product vtable | Collect/Deliver overwrite `*this` after call | **Falsified as final** — temporary base only |
| 5 | `__cdecl` / no cleanup | Epilogue `C2 04 00` | **Falsified** — thiscall RET 4 |
| 6 | Returns void / nothing in EAX | `8B C1` saves this to EAX; never clobbered | **Falsified void** — returns this |
| 7 | Has callees / heap work | Body 18 bytes, no CALL | **Falsified** — leaf |
| 8 | Single production caller | 14 UNCONDITIONAL_CALL xrefs | **Falsified single** — shared base |
| 9 | Class is Collect RTTI | String is bare `.?AVCVOGObjectiveRequirement@@` | **Falsified Collect-only** |
| 10 | Parent written at `+0x08` | Store is `89 48 04` → `+0x04` | **Falsified** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ABI RET 4 / thiscall | **Confirmed** | crash in reimpl |
| vfptr imm `0x009e3bac` | **Confirmed** | wrong base virtuals |
| parent @ `+0x04` | **Confirmed** | owner null / wrong |
| Shared base for all req types | **High** | wrong call graph |
| RTTI base name | **High** | name churn only if string wrong |
| Final subclass type codes | **N/A here** | owned by subclass ctors |
| Runtime | **Open** | — |

---

## 3. Byte anchors (adversarial re-read)

```text
0x00637da0:
  8B C1                 mov eax, ecx
  8B 4C 24 04           mov ecx, [esp+4]     ; parent
  C7 00 AC 3B 9E 00     mov dword [eax], 009E3BACh
  89 48 04              mov [eax+4], ecx
  C2 04 00              ret 4
```

No room for type store, float init, or second pointer field.

Collect call pattern (external, already dual-sealed):

```text
; after CALL 0x00637da0
C7 06 C4 12 9E 00       ; *this = Collect vtable (overwrites base)
C7 46 0C 02 00 00 00    ; type = 2
```

---

## 4. What would reverse the seal?

- Live body writing more than vfptr+parent (different image).
- RTTI string at related TypeDescriptor not matching `CVOGObjectiveRequirement`.
- A production requirement ctor that does **not** call this VA for base init (would demote “shared” claim only).

None observed on current `autoassault.exe` static image.

---

## 5. Gaps (aligned with A)

1. Base vfptr slot English names.  
2. Per-caller parent semantics.  
3. Runtime / bit-exact.  
4. Full factory dispatch (parent residual).

**Verdict:** **accept-with-gaps** — adversarial pass keeps base ctor sealed; subclass type codes remain subclass-owned.
