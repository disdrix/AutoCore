# Review B (skeptical / adversarial): `aa_0073d8d0` EffEffectFactory_OnDeviceLost_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0073d8d0` |
| **VA** | `0x0073d8d0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` |
| **Counterpart** | `reviews/A_aa_0073d8d0_EffEffectFactory_OnDeviceLost_Inferred.md` |
| **Evidence** | Live decompile + full-body `read_memory` 103 B + sole caller context + pair `0073d870` + callee decompiles |
| **Agent** | W38-V OWN-ONLY |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | ECX thiscall | Call site loads **EAX** only | **Falsified thiscall** |
| 2 | Post-Reset recreate | Called in shutdown **before** D3D Reset, before factory rebuild chain | **Falsified OnReset** — OnLost polarity |
| 3 | Returns status like pair | No `XOR EAX,EAX`; void; caller does not test | **Falsified status return** |
| 4 | Different host than 0073d870 | Both use `[EBP+0x764]` | **Falsified different host** — same factory |
| 5 | `DAT_00d1f044[0x1df]` is byte flag | `CMP DWORD [EAX+0x77C],1` | **Sealed dword** at +0x77C |
| 6 | Product OnLostDevice name sealed | Structural + phase only | **Accepted gap** — `_Inferred` |
| 7 | Scaffold Named_CalleeOf_gfxDevice | gfxDevice is **caller**, not body identity | **Rejected scaffold** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| EAX host; void RET | **Confirmed** | Wrong call convention |
| 0x14 walk + release callees | **Confirmed** | Incomplete lost path |
| Pre-reset / OnLost polarity | **Confirmed** | Swap with pair |
| Global clear + mode vcall | **Confirmed** | Device state leak |
| Product class English | **Open** | Doc-only |
| vtbl +0x134 product plate | **Probable** | Misnamed helper only |
| Runtime | **Open** | — |

---

## 3. Cross-check vs callers / pair

| Site | Pattern |
|---|---|
| `FUN_0075eff0` @ `0x0075f0f7` | After IB/VB/BufferedViews teardown helpers; `MOV EAX,[EBP+0x764]; CALL 0073d8d0`; then texture list / more teardown / D3D Reset |
| Pair `0073d870` | Same host after Reset success — complementary |
| Caller later | Uses `param_1[0x1df]` and vtbl`+0x134` with 0/1 — same device mode field family as this tail |

---

## 4. Byte anchors

```text
0x0073d8d0: 51 53 8B 58 08 57 8B 78 04   ; EBX=end; EDI=begin
            … E8 … → FUN_0074f0c0
            … E8 … → FUN_00752640
            … 83 C7 14 …                 ; stride 0x14
            A1 48 F0 D1 00 C6 40 0C 00   ; DAT_00d1f048[+0xC]=0
            A1 44 F0 D1 00 83 B8 7C 07 00 00 01  ; [+0x77C]==1?
            … 6A 00 50 FF 91 34 01 00 00 59 C3   ; vcall +0x134(0)
```

---

## 5. What would reverse the seal?

- Proof post-Reset placement — contradicted by shutdown-phase call order.
- Proof different host than Effect Factory reset — contradicted by identical `[EBP+0x764]`.
- Proof thiscall ECX — contradicted by EAX load at call site.
- Proof no global tail — contradicted by `DAT_00d1f048` / `DAT_00d1f044` bytes.

None observed.

**Verdict:** **accept-with-gaps**
