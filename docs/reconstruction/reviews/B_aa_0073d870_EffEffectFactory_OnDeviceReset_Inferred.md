# Review B (skeptical / adversarial): `aa_0073d870` EffEffectFactory_OnDeviceReset_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0073d870` |
| **VA** | `0x0073d870` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` |
| **Counterpart** | `reviews/A_aa_0073d870_EffEffectFactory_OnDeviceReset_Inferred.md` |
| **Evidence** | Live decompile + full-body `read_memory` 82 B + sole caller context + pair `0073d8d0` |
| **Agent** | W38-V OWN-ONLY |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | ECX thiscall host | Call site `MOV EAX,[EBP+0x764]; CALL` — no ECX setup | **Falsified thiscall** — EAX formal |
| 2 | Returns HRESULT failure paths | Body ends `XOR EAX,EAX` only | **Falsified multi-status** — always 0 |
| 3 | Pre-reset / OnLost role | Called **after** IB/VB/Texture/BufferedViews reset succeeds | **Falsified OnLost** — post-Reset recreate |
| 4 | Stride 4 / dword vector of hosts | `ADD EBX,0x14`; decomp `piVar4+5` | **Falsified stride-4** — entry 0x14 |
| 5 | Product name `effEffectFactory::OnReset` sealed | No body string; name from caller plate + structural | **Accepted gap** — `_Inferred` only |
| 6 | Vcall +0x118 is ID3DXEffect::OnResetDevice | Slot sealed; product method English open | **Accepted gap** |
| 7 | Scaffold Named_CalleeOf_gfxDevice | Caller is gfxDevice but unit is Effect Factory factory walk | **Rejected scaffold** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| EAX host; return 0; RET | **Confirmed** | Caller contract break |
| 0x14 entry walk + child +0x118 | **Confirmed** | Wrong recreate path |
| Effect Factory role | **Confirmed** | Mis-home under wrong factory |
| OnReset (vs OnLost) polarity | **Confirmed** | Swap with pair |
| Product class English | **Open** | Doc-only |
| Runtime | **Open** | — |

---

## 3. Cross-check vs callers / pair

| Site | Pattern |
|---|---|
| `FUN_0075eff0` @ `0x0075f2f6` | `MOV EAX,[EBP+0x764]; CALL 0073d870; TEST EAX,EAX; JGE …` else push **"Failed to Reset() device on Effect Factory"** |
| Pair `0073d8d0` @ `0x0075f0f7` | Same `[EBP+0x764]` during **shutdown** phase — complementary polarity |

Neighbor table walkers (`0073d7d0`/`0073d830`/`0073d940`) share 0x14 stride on same host shape — registry/factory family, not contradicting Effect Factory plate.

---

## 4. Byte anchors

```text
0x0073d870: 51 53 8B 58 04 57 8B 78 08   ; frame; EBX=begin; EDI=end
            … 83 78 0C 00 … FF 91 18 01 00 00  ; child? vcall +0x118
            … E8 … → FUN_007525f0
            … 83 C3 14 …                 ; stride 0x14
            5E 5D 5F 33 C0 5B 59 C3      ; return 0
```

---

## 5. What would reverse the seal?

- Proof ECX thiscall with different host — contradicted by call-site EAX load.
- Proof non-zero failure return — contradicted by `XOR EAX,EAX` sole exit.
- Proof pre-reset placement — contradicted by order after D3D Reset success chain.
- Proof non-Effect-Factory host — contradicted by sole fail string.

None observed.

**Verdict:** **accept-with-gaps**
