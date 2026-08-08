# Review B (skeptical / independent): `aa_0051d7c0` Map_EraseRange_Isnil15

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051d7c0` |
| **VA** | `0x0051d7c0` |
| **Canonical name** | `Map_EraseRange_Isnil15` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Skeptical naming / anti-overclaim |
| **Counterpart** | `reviews/A_aa_0051d7c0_Map_EraseRange_Isnil15.md` |
| **System** | STL / map-set |
| **Verdict** | **accept-with-gaps** — agree with A |

---

## 1. Adversarial read of proposed names

| Candidate | Ruling |
|---|---|
| `FUN_0051d7c0` only | Scaffold only; under-describes sealed role |
| `Map_EraseRange` | **Reject as identity** — that name is isnil@+0x29 (`0x0051c7c0`) |
| `Map_EraseRange_B` | **Reject** — isnil@+0x29 + free `0051be90` |
| `StdMap_EraseRange_Inferred` | **Reject as identity** — reserved `0x004bacf0` (free `004ba770` / erase `004baa30`) |
| `Map_EraseRange_C` | Weaker — letter series already used for isnil29 twins; isnil offset clearer |
| `Skill_*` / cast-map names | **Reject** — no cast-binding-only evidence; multi-caller generic STL |
| `Map_EraseRange_Isnil15` | **Accept** — structural + sealed isnil discriminator |

---

## 2. Attacks on A's CF claims

| Attack | Result |
|---|---|
| Only full clear (no partial) | **Fails** — successor loop + `FUN_0051ce00` present |
| List erase not tree | **Fails** — parent climb / right-min successor |
| Same family as Map_EraseRange (+0x29) | **Fails** — gate uses `+0x15` |
| Bit-identical to `0x004bacf0` | **Fails** — free/erase call targets differ |
| `ret 8` like single-iterator erase | **Fails** — both exits `ret 0x0c` |
| Decomp shows erase without this | **Trap only** — bytes `mov ecx, edi` before call |

---

## 3. Agreement with Review A

- STL range-erase role + ABI + dual paths: **agree Confirmed/High**
- isnil@+0x15 discriminator: **agree Confirmed**
- Structural name without product English: **agree**
- Gaps (payload types, nested free/erase dual, runtime): **agree open**

---

## 4. Residual risks

- Free-subtree `FUN_0051be50` / erase `FUN_0051ce00` not dual-sealed this pass — do not invent value-dtor English.
- Do not registry-merge with `StdMap_EraseRange_Inferred` without callee check.
- `FUN_0052f260` host English open — do not claim skill-cast map.

**Verdict:** **accept-with-gaps**
