# Review B (skeptical / adversarial): `aa_004248c0` Rng_Mt19937_Twist

| Field | Value |
|---|---|
| **Stable ID** | `aa_004248c0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W18-K OWN-ONLY dual) |
| **Counterpart** | `reviews/A_aa_004248c0_Rng_Mt19937_Twist.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | `__thiscall` / ECX this | Entry `MOV EAX,ESI`; no ECX use; extract sets **ESI** | **Falsified** — **ESI state** |
| 2 | Has stack args / RET N | Ends **`C3`** near ret; no `C2` | **Falsified** — **0 stack args** |
| 3 | Is temper / extract | No right-shift temper cascade; full 624 rewrite + cursor reset | **Falsified** — **twist only** |
| 4 | Is seed init (`0x6c078965`) | No `0x6c078965`; uses `0x9908b0df` | **Falsified** — twist, not seed |
| 5 | Remaining set to 0 after twist | Bytes write **`0x270`** to `+0x9c4` | **Falsified** — remaining=**N** |
| 6 | Cursor points past end | Writes **`esi`** (start) to `+0x9c0` | **Falsified** — cursor=`&mt[0]` |
| 7 | Decompiler `unaff_ESI` is junk | Extract caller: `MOV ESI,EAX` then `CALL 004248c0` | **Confirmed real ESI ABI** |
| 8 | Non-standard N/M | Loops 227+396+1 = 624; lag 397 | **Confirmed standard MT19937** |
| 9 | Has callees | `analyze_function_complete` callees **[]** | **Confirmed leaf** |
| 10 | Scaffold “unknown system” | Constants + 22 xrefs into RNG fill/extract | **System is RNG/MT19937** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| MT19937 identity | **High** | Wrong PRNG breaks skills/dice tables |
| ESI ABI | **High** | Crash / corrupt wrong object |
| cursor@+0x9c0 remaining@+0x9c4 | **High** | Extract desync / infinite twist |
| MATRIX_A / N / M | **High** | Non-matching stream vs client |
| Product English name | **Medium** | Naming only |
| Last-element lag = mt[M−1] | **High** | Classic wrap; pointer form matches |

---

## 3. Cross-check against raw + bytes

```
raw:
  i=0xe3 loop with p[0x18d] and MATRIX_A 0x9908b0df
  i=0x18c loop with p[-0xe3]
  last with *unaff_ESI and puVar1[-0xe2]
  unaff_ESI[0x271]=0x270; unaff_ESI[0x270]=(uint)unaff_ESI

bytes @ 004248c0:
  8BC6 BAE3000000 57 ... 81E1DFB00899 ...
  BA8C010000 ...
  C786C409000070020000 89B6C0090000 C3

extract sibling @ 00424830 (context):
  if [esi+0x9c4]==0 call twist
  dec [esi+0x9c4]
  load **[esi+0x9c0], advance cursor, temper

≡ consistent MT buffer + countdown extract model (not classic mti index).
```

---

## 4. Surviving contract for AutoCore

```csharp
// Client MT19937 twist (state layout used by extract).
void RngMt19937Twist(Mt19937State st)
{
    // N=624, M=397, MATRIX_A=0x9908B0DF — standard twist
    // ... regenerate st.mt[0..623] ...
    st.Remaining = 624;      // +0x9c4
    st.Cursor = st.Mt;       // +0x9c0
}
```

- Server skill/dice ports that must match client streams need **this** twist + the extract temper (separate unit).
- Do not confuse with seed init `0x6c078965` or the 2 MiB ushort clone table.
- Object size **0x9c8** at `operator_new` sites.

---

## 5. Gaps surviving review

1. Product / PDB name.
2. Extract temper mask exactness (sibling unit).
3. Runtime vector test vs known MT19937 outputs (seed path may differ slightly from reference if temper differs).
4. Bit-exact image diff.

**Verdict:** **accept-with-gaps** — twist CF, constants, ESI ABI, cursor/remaining **sealed**.
