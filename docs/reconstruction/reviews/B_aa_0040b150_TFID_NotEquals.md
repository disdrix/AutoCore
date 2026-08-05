# Review B (skeptical / adversarial): `TFID_NotEquals` @ `0x0040b150`

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040b150` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0040b150_TFID_NotEquals.md` |
| **Verdict** | **accept** on CF/polarity/width; **needs-more-evidence** only on product TFID field names beyond this unit |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Compares full 16-byte TFID | **Falsified** — only `i32@0`, `i32@4`, `i8@8` (body bytes; no loads past +8) |
| 2 | Equal returns 1 (like Equals) | **Falsified** — equal path ends AL=0 via `sete` invert; name is NotEquals |
| 3 | `__stdcall` / thiscall | **Falsified** — `[esp+4]/[esp+8]` formals, plain `ret` |
| 4 | Side effects / writes | **Falsified** — pure loads + cmp + ret |
| 5 | Decompiler CF wrong vs assembly | **Falsified** — decomp matches byte path (equal→0, unequal→1) |
| 6 | `sete` path is obfuscation changing semantics | **Survives as style only** — net polarity is standard NotEquals |
| 7 | Safe to treat as full TFID_16 `memcmp` | **Falsified** — trailing 7 bytes ignored; distinct TFID_16 can collide if only tail differs |
| 8 | Runtime / bit-exact EXE verified | **Open** — deferred; static body only |
| 9 | Param types sealed as `TFID_16*` | **Overstated if claimed sealed** — consumers pass TFID buffers; Ghidra `void*` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Polarity equal→0 / unequal→1 | **Confirmed** | Inverted gate → cast/busy / target checks flip |
| Compare width 4+4+1 | **Confirmed** | Porting full-16 equality → false mismatches or false matches |
| `__cdecl` two ptrs | **Confirmed** | Wrong CC → stack corruption |
| Leaf / no callees | **Confirmed** | Low |
| Name fidelity | **High** | Twin Equals at `0x00404aa0` sealed same width |
| Product meaning of +0/+4/+8 fields | **Medium** | Layout docs call them ObjectId/COID-like; not proved inside this leaf |
| Sentinel values | **N/A here** | Caller-supplied; wrong sentinel is caller bug |

---

## 3. Surviving contract for AutoCore

```
TFID_NotEquals(a, b) -> 0 if a[0..3]==b[0..3] && a[4..7]==b[4..7] && a[8]==b[8]; else 1
// NOT memcmp(a,b,16)
// Twin: TFID_EqualsObjectId = !TFID_NotEquals  (same width)
```

Port rule: any "TFID free / invalid / different target" check that calls this helper must only rely on the ObjectId key, not on the high 7 pad/type bytes.

---

## 4. Assembly contract (from `read_memory`)

```
0040b150  8b442404    mov  eax, [esp+4]      ; pA
0040b154  8b10        mov  edx, [eax]
0040b156  8b4c2408    mov  ecx, [esp+8]      ; pB
0040b15a  3b11        cmp  edx, [ecx]
0040b15c  751f        jne  unequal
0040b15e  8b5004      mov  edx, [eax+4]
0040b161  3b5104      cmp  edx, [ecx+4]
0040b164  7517        jne  unequal
0040b166  8a4008      mov  al,  [eax+8]
0040b169  3a4108      cmp  al,  [ecx+8]
0040b16c  750f        jne  unequal
; equal:
0040b16e  b801000000  mov  eax, 1
0040b173  33c9        xor  ecx, ecx
0040b175  84c0        test al, al
0040b177  0f94c1      sete cl                ; cl=0
0040b17a  8ac1        mov  al, cl            ; return 0
0040b17c  c3          ret
; unequal:
0040b17d  33c0        xor  eax, eax
0040b17f  33c9        xor  ecx, ecx
0040b181  84c0        test al, al
0040b183  0f94c1      sete cl                ; cl=1
0040b186  8ac1        mov  al, cl            ; return 1
0040b188  c3          ret
```

Hex (body through ret):  
`8b4424048b108b4c24083b11751f8b50043b510475178a40083a4108750fb80100000033c984c00f94c18ac1c333c033c984c00f94c18ac1c3`

---

## 5. Open questions

1. Formal product names for the three compared fields (COID lo/hi + type byte?) — sibling layout, not this leaf.
2. Whether any retail path depends on bytes +9…+15 remaining unequal while ObjectId key matches (would be invisible to this helper).
3. Full caller-site polarity audit (which sites treat return≠0 as "free/invalid" vs "different object") — per-caller work.

**Verdict:** **accept** on sealed CF/polarity/width; do **not** document or port as full 16-byte TFID compare. Sibling type/layout recovery remains open outside this unit.
