# Review B (skeptical / adversarial): `aa_0050846f` CVOGHBBase_EndOrDestroy_SoftMarkEpilogue

| Field | Value |
|---|---|
| **Stable ID** | `aa_0050846f` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W21-B OWN-ONLY dual) |
| **Counterpart** | `reviews/A_aa_0050846f_CVOGHBBase_EndOrDestroy_SoftMarkEpilogue.md` |
| **System** | heartbeat / CVOGHBBase |
| **Dual status** | **Present** |
| **Verdict** | **accept** on CF + ABI fragment + field stores; **reject** MissionPatrol seed naming and any free-standing API claims |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Normal function with prologue / stack args | **Falsified** — no prologue; unaff regs; parent frame epilogue |
| 2 | Soft stores live in hard fragment `0050843d` | **Falsified** — hard body ends `00508463`; stores at `0050846f+` |
| 3 | Has callees (list unlink, vtbl) | **Falsified** — leaf; unlink is parent hard path only |
| 4 | MissionPatrol primary role | **Falsified** — sole xrefs from `FUN_0050843d` / EndOrDestroy family |
| 5 | Returns a status in EAX | **Falsified** — void path; epilogue does not set AL/EAX for caller value |
| 6 | `ret` without stack cleanup | **Falsified** — `ret 8` |
| 7 | Body longer than epilogue hex | **Falsified** — full body 25 payload bytes + pad boundary |
| 8 | Product name proven | **Fail** — inferred; does not block accept |
| 9 | Needs `disassemble_bytes` for seal | **Falsified** — `read_memory` seals entire fragment |

---

## 2. Decisive evidence

### Full body hex

`c6462001 895e18 8b4df4 5f5e 64890d00000000 5b 8be5 5d c20800`

Straight-line. No hidden side paths.

### Parent fall-through

Hard-unlink dual already sealed: all four sites in `FUN_0050843d` land here after optional `FUN_005085b0` remove-by-key.

### Seed name supersession

`Named_CalleeOf_*_CVOGHBMissionPatro_0050846f` is a parent-seed scan artifact. Xrefs do not support MissionPatrol as primary owner.

---

## 3. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Soft mark / clear CF | **High** | Broken HB end path |
| Field offsets `+0x18/+0x20` | **High** | Wrong HB layout |
| Fragment vs free API | **High** | Wrong port ABI |
| Product name | **Tentative** | Naming only |
| Runtime soft path golden | **Open** | — |

---

## 4. What would falsify accept

1. Additional xrefs with different entry ABI.
2. Proof soft stores occur elsewhere for the same EndOrDestroy path.
3. Bytes differ in another image build.

None observed in this program.

---

## 5. Verdict

**accept.** Fragment is byte-complete. Prefer `CVOGHBBase_EndOrDestroy_SoftMarkEpilogue` over MissionPatrol seed name. Residual: product symbol + runtime only.
