# Review B (skeptical / adversarial): `aa_00604db0` CVOGHBBase_SetPartnerLink

| Field | Value |
|---|---|
| **Stable ID** | `aa_00604db0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W20-S OWN-ONLY dual) |
| **Counterpart** | `reviews/A_aa_00604db0_CVOGHBBase_SetPartnerLink.md` |
| **System** | `object / combat-target / HB` |
| **Dual status** | **Present** |
| **Verdict** | **accept** on CF + ABI + field roles; **reject** DriveControlTick-primary naming and any non-leaf claims |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Always writes `+0x24` | **Falsified** — same-owner non-null skips |
| 2 | Compares vtbl or type id at `+0x18` | **Falsified vs family seals** — `+0x18` is owner object from AttachOwner |
| 3 | DriveControlTick direct callee | **Falsified** — only `Object_SetSelectedTarget` xrefs |
| 4 | Allocates or starts HB | **Falsified** — leaf, no callees |
| 5 | Returns success code | **Falsified** — void; no EAX set |
| 6 | `ret` without stack cleanup | **Falsified** — `ret 4` |
| 7 | Scaffold DriveControlTick name is authoritative | **Falsified** — seed misname; superseded |
| 8 | Product name proven | **Fail** — inferred family only; does not block accept |
| 9 | Needs disassembly for CF | **Falsified** — `read_memory` seals entire body |

---

## 2. Decisive evidence

### Full body hex

`8b442404 85c0 7408 8b5018 3b5118 7403 894124 c20400` + int3 pad.

Five real instructions. No hidden side paths.

### Parent call sites (from sealed `Object_SetSelectedTarget`)

- `push partner; mov ecx, this; call 0x00604db0` both directions.
- Parent decomp drops stack args; **this leaf does not** — stack arg visible as `[esp+4]`.

### Owner field

Multiple independent duals (`CVOGHBBase_ctor` family, targeting ctors, residual `a_0051e3b0`) store owner at `+0x18`. Comparing `+0x18` as owner equality is the only reading consistent with those seals.

---

## 3. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Write gate CF | **High** | Broken partner clear/link |
| Field offsets | **High** | Wrong HB layout |
| Owner meaning of `+0x18` | **High** | Mis-modeled gate |
| Partner meaning of `+0x24` | **High** | Targeting unlink bugs |
| C++ product name | **Tentative** | Naming only |
| Same-owner hit rate in retail | **Open** | Gate may be defensive-only |

---

## 4. What would falsify accept

1. Additional xrefs with different ABI.
2. Proof `+0x18` is not owner on this subclass (would re-label gate, not CF).
3. Bytes differ in another image build.

None observed in this program.

---

## 5. Verdict

**accept.** Leaf is byte-complete. Prefer `CVOGHBBase_SetPartnerLink` over DriveControlTick seed name. Residual: product symbol + runtime golden only.
