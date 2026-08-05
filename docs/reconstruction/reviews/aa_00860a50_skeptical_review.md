# Skeptical / adversarial review: `Client_UI_InventoryDropToGrid` @ `0x00860a50`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00860a50` |
| **Review type** | Skeptical / adversarial |
| **Date** | 2026-07-23 |
| **Scope** | UI drop-to-grid C2S unit + package claims |
| **Verdict** | **needs-more-evidence** |

---

## 1. What was inspected

Primary unit raw/annotated/clean/function record; system map; wire RE locker section; networking opcode notes; sibling grab `aa_00860e20` for busy flag and send helper comparison.

**Not performed:** asm of CONCAT packing, live drop, caller xrefs for `in_EAX`.

---

## 2. Evidence used

Raw establishes:

1. Multi-gate UI validation before any send.
2. Inventory type from `*(in_EAX[0x15b]+4)`.
3. Three send-shaped outcomes: fail toast (0), busy noop (1), build packet + `Client_SendSectorPacket` (1).
4. Grid path size `0x20` with opcode bytes forming `0x2036`; store-like path size `0x40` with opcode `0x2027`.
5. Trade type `5` string blocks; class-`4` interactions with store validation `FUN_00513770`.

---

## 3. Attack results

### Claim 1 — Function is “only” InventoryDrop `0x2036`

| Sub-claim | Result |
|-----------|--------|
| Grid path encodes `0x2036` size `0x20` | **Holds** (`'6'` + `' '` + 0 + 0). |
| Function exclusively sends `0x2036` | **FALSIFIED.** Type-4 / special paths send `0x27` size `0x40`. |
| Name `…DropToGrid` covers all exits | **Over-narrow.** Store sell / special cd0 path is not pure grid drop. |

### Claim 2 — Early allows types 1 and 3 only (cargo/locker)

| Sub-claim | Result |
|-----------|--------|
| Gate: if type≠3 ∧ type≠1 ∧ class==4 → return 0 | **Holds as written.** |
| Types 1 and 3 always allowed | **Overstated.** Gate only blocks a subset (non-1/3 **and** class 4). Type 2/4/5/6 can still proceed depending on later branches. |
| Wire RE “early allows types 1 and 3” | **Partial paraphrase** of one conjunct — easy to misread as exclusive allow-list. |

### Claim 3 — XY placement packed correctly in clean

| Sub-claim | Result |
|-----------|--------|
| Clean preserves CONCAT11/CONCAT12/extraout_EDX | **Yes (fidelity).** |
| That packing is understood / correct retail math | **Not sealed.** `extraout_EDX`, `FUN_0085f1d0` return, `in_EAX[0x159]` scale — decompiler soup. **Critical for port parity.** |

### Claim 4 — Busy flag semantics

| Sub-claim | Result |
|-----------|--------|
| `DAT_00d1a8f6 != 0` → return 1 without send | **Holds.** |
| Shared with grab path | **Survives** (same global in grab unit). |
| Return 1 means “drop accepted” | **Falsified as success** — busy fake-success possible. |

### Claim 5 — Signature is `void` / no args

| Sub-claim | Result |
|-----------|--------|
| Decompiler `void` + `in_EAX` | **Holds as Ghidra output.** |
| Portable C API | **Broken** — implicit this in EAX; not expressed in clean signature. |

### Claim 6 — Trade restrictions sealed

| Sub-claim | Result |
|-----------|--------|
| Type 5 + bit20 customized message | **CF holds.** |
| Type 5 + byte `+0x4be` no-trade | **CF holds.** |
| Bit/byte semantic names | **Narrative only** (strings prove user-facing reason, not bit taxonomy). |

### Claim 7 — Clean exact / complete

Scaffold fidelity **yes**; retail understanding **no** — opaque pack, dual opcodes, unresolved DAT/FUN.

---

## 4. Alternate interpretations

### Minimal reading

UI method that:

1. Resolves drop target type + hit cell.
2. Rejects illegal class/type combinations and some trade cases.
3. Either pretends success if busy, or emits **one of two** sector packets (grid drop vs store-like), or shows an error.

### Competing type-4 stories

1. Vendor/store sell packet (`0x2027`).
2. Equip-to-hardpoint path mislabeled (less likely given size 0x40 and store string).
3. Shared builder for multiple “drop-like” actions.

---

## 5. Confirmed despite skepticism

1. Dual success packet sizes `0x20` / `0x40`.
2. Grid opcode materializes as `0x2036`.
3. Trade user-visible reject strings.
4. Shared busy global with grab.
5. Clean does not silently drop branches.

---

## 6. Critical contradictions / package risks

### C1 — Name vs dual opcode

Calling the unit pure InventoryDrop `0x2036` erases the `0x2027`/0x40 path.

### C2 — “Allows only 1 and 3” vs actual gate

Wire-doc shorthand is easy to over-read; binary gate is weaker than exclusive allow-list.

### C3 — Coordinate packing unsealed

Any server that trusts client XY needs independent layout recovery — not this scaffold.

**No CF self-contradiction inside raw body** for the multi-branch structure.

---

## 7. Residual uncertainty

| # | Item | Blocks seal? |
|---|------|--------------|
| R1 | EAX this type / field map `0x15b/0x15d/0x159` | Yes |
| R2 | Drop 0x20 field diagram | Yes |
| R3 | 0x27 path identity | Yes |
| R4 | Hit-test helpers | Yes |
| R5 | Runtime | Yes |

---

## 8. Concrete checks performed

1. Re-derived all major predicates from raw.
2. Converted opcode char `'6'` / `'\''` to LE dword values.
3. Line-compared clean vs raw.
4. Attacked exclusive type-1/3 allow-list reading of wire RE.
5. Attacked “only 0x2036” naming.
6. Compared busy flag to grab sibling.
7. Flagged CONCAT packing as non-understood.

---

## 9. Verdict

### **`needs-more-evidence`**

Scaffold CF is intact; interpretation package oversimplifies multi-opcode behavior and has unsealed coordinate packing. Not a critical decompile self-contradiction.

### Stronger-verdict bar

1. Asm or better decompile of XY packing.
2. Typed drop packet struct vs server.
3. Identity of `0x2027` path (store).
4. Caller + this-object layout.
5. Live drop cargo/locker capture.

---

## 10. Scorecard

| # | Claim | Result |
|---|-------|--------|
| 1 | Only 0x2036 | **Fail (dual opcode)** |
| 2 | Exclusive 1/3 allow | **Overstated** |
| 3 | XY packing understood | **Fail seal** |
| 4 | Busy return = success | **Fail** |
| 5 | Signature complete | **Fail** |
| 6 | Trade string gates CF | **Hold** |

**Final verdict: `needs-more-evidence`**
