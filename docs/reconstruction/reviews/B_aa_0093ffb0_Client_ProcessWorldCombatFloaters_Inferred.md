# Review B (skeptical / adversarial): `aa_0093ffb0` Client_ProcessWorldCombatFloaters_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0093ffb0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0093ffb0_Client_ProcessWorldCombatFloaters_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Same as `Client_EnqueueCombatFloater` 0x38 queue | Builds **0x60** widgets + world distance; different pipeline | **Falsified** as identical |
| 2 | Unlimited range floaters | `SQRT` vs `DAT_00aaa9f0` = 60.0f | **Falsified** |
| 3 | Accepts all object types | Only clone types `0xe/0x12/0x14` | **Falsified** |
| 4 | Single floater kind | `switch` cases 0–4 with distinct colors/text | **Falsified** |
| 5 | No self/other distinction | `TFID_EqualsObjectId` sets `bVar4`/`bVar5` tints | **Falsified** |
| 6 | ECX thiscall | Stack client via `PUSH`; prologue load from `[esp+…]` | **Falsified** as ECX this |
| 7 | All side paths High CF | Tips, panels, select hooks — not fully exhaustively dual-traced | **Gap** — core loop High, residuals Probable |

---

## 2. Confidence table

| Area | Confidence | Risk if wrong |
|---|---|---|
| Client stack this | **High** | Wrong ABI |
| Distance 60.0 gate | **High** | Floaters at wrong range |
| Type filter 0xe/12/14 | **High** | Spam floaters |
| Kind switch 0..4 | **High** | Wrong chrome |
| Deflect/Resist string paths | **High** | |
| Every tip/UI side branch | **Probable** | Miss first-time UX |
| Product kind enum English | **Open** | Doc |
| Runtime | **Open** | |

---

## 3. Surviving contract

```c
// stack Client*
void Client_ProcessWorldCombatFloaters(Client* client);
```

- Requires local char + `char+0x250`.
- Walks pending events at `*(client+0xe04)+0xe8a8..e8ac`.
- In-range (≤60) typed targets → allocate floater, style by kind, insert/adjust list at `client+0xaac`.
- May fire first-time tips and optional select/UI hooks.

---

## 4. Verdict

**accept-with-gaps** — adversarial seals distance/type/kind core against conflation with 0x38 enqueue helper. Side-branch product English open.
