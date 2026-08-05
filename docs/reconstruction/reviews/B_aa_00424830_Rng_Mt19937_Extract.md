# Review B (skeptical / adversarial): `aa_00424830` Rng_Mt19937_Extract

| Field | Value |
|---|---|
| **Stable ID** | `aa_00424830` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W20-C OWN-ONLY dual) |
| **Counterpart** | `reviews/A_aa_00424830_Rng_Mt19937_Extract.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | `__thiscall` / ECX this | Entry `mov esi,eax`; no ECX use | **Falsified** — **EAX state** |
| 2 | ESI entry like twist | Twist is ESI; this **loads ESI from EAX** | **Distinct entry ABI** |
| 3 | Is twist itself | No MATRIX_A / no 624 rewrite | **Falsified** — extract + temper |
| 4 | Is seed (`0x6c078965`) | No init mult | **Falsified** |
| 5 | Non-standard temper | Shifts 11/7/15/18; masks ≡ classic | **Confirmed standard MT19937** |
| 6 | Masks must match textbook encoding | Body pre-shift AND form | **Bit-equivalent** to `0x9d2c5680` / `0xefc60000` |
| 7 | Remaining not decremented | `add dword [esi+0x9c4], -1` | **Falsified** — decrements |
| 8 | Cursor not advanced | `add eax,4; mov [esi+0x9c0],eax` | **Falsified** — advances |
| 9 | Decompiler `in_EAX` is junk | Matches `mov esi,eax` | **Real EAX ABI** |
| 10 | Scaffold “unknown system” | Sibling twist dual + 34 RNG xrefs | **System is RNG/MT19937** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| MT19937 extract identity | **High** | Wrong client rolls / desync |
| EAX ABI + return | **High** | Crash / wrong stream |
| cursor@+0x9c0 remaining@+0x9c4 | **High** | Infinite twist / OOB |
| Temper steps | **High** | Non-matching stream |
| Product English name | **Medium** | Naming only |
| Per-caller state object | **Medium** | Port may use wrong engine |

---

## 3. Cross-check against raw + bytes + siblings

```
raw:
  if [eax+0x9c4]==0 call FUN_004248c0
  --remaining; y=*cursor++; temper; return

bytes @ 00424830:
  56 8BF0 83BEC409000000 75 05 E8… → 004248c0
  temper immediates AD 58 3A FF / 8C DF FF FF
  ends 5E C3

twist sibling @ 004248c0 (context, dualed W18-K):
  after twist remaining=0x270, cursor=esi
  extract consumes that buffer one dword at a time

seed sibling @ 00424890 (context, dualed W19-A):
  fills mt[624] with F=0x6c078965; does NOT set cursor/remaining
```

≡ consistent countdown-buffer MT API (not classic mti index form).

---

## 4. Surviving contract for AutoCore

```csharp
// Client MT19937 extract-one (state layout shared with twist/seed).
uint RngMt19937Extract(Mt19937State st) // st in EAX on retail
{
    if (st.Remaining == 0)
        RngMt19937Twist(st);     // ESI ABI sibling
    st.Remaining--;
    uint y = *st.Cursor++;
    y ^= y >> 11;
    y ^= (y & 0xFF3A58AD) << 7;
    y ^= (y & 0xFFFFDF8C) << 15;
    return (y >> 18) ^ y;
}
```

- Server/client ports that must match retail streams need **this** temper + the twist sibling.
- Do not substitute libc `rand` or a different MT temper.
- Object size **0x9c8**.

---

## 5. Gaps surviving review

1. Product/PDB name.
2. Global vs per-object engine ownership for each of 34 call sites.
3. Runtime vector test after seed→twist→extract chain.
4. Bit-exact image diff.

**Verdict:** **accept** — extract CF, EAX ABI, temper, twist link, cursor/remaining **sealed**.
