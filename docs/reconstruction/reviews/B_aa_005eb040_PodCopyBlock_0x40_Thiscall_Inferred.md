# Review B (skeptical / adversarial): `aa_005eb040` PodCopyBlock_0x40_Thiscall_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005eb040` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (R12-036 OWN-ONLY dual B) |
| **Counterpart** | `reviews/A_aa_005eb040_PodCopyBlock_0x40_Thiscall_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Identity is VOG_DEBUG_STOP / spawn scaffold | long `Named_CalleeOf_*VOG_DEBUG_STOP*` chain | **Falsified** — pure 16-dword POD copy; no debug/stop paths |
| 2 | Is the query-object base ctor itself (`005eb210`) | parent residual naming bleed | **Falsified** — leaf only; parent *calls* this for `+0x80` tail |
| 3 | Is a vector PodCopy element leaf (0x10/0x28 family) | R10 PodCopy naming pattern | **Falsified** — thiscall stack-src + **16** dwords + `RET 4`; not EAX/ECX single-element |
| 4 | Is `memcpy` / `REP MOVSD` helper | size-family guess | **Falsified** — unrolled dword stores only; fixed 0x40 |
| 5 | stdcall / bare RET / free function (no this) | classification noise | **Falsified** — `MOV EAX,ECX`; `RET 4`; call sites LEA dest into ECX |
| 6 | Returns void / does not return dest | decompiler `void` + `return_type undefined` | **Falsified** — EAX holds dest through RET (prolog `MOV EAX,ECX`) |
| 7 | Copies 0x3C only (15 dwords) or 0x44 (17) | off-by-one on last store | **Falsified** — stores through `+0x3C` inclusive = 16 dwords = 0x40 |
| 8 | Direction is src←dest or ECX=src | decompiler param naming confusion | **Falsified** — ECX entry = dest; stack = src; call sites LEA dest into ECX, PUSH src |
| 9 | Deep copy / vtbl / constructor side effects | ctor-family bleed | **Falsified** — no calls, no vtbl writes, pure POD stores |
| 10 | Domain-locked to query-object only | partition system label | **Falsified as exclusive** — 29 xrefs across many families; still correctly *used by* query base ctor |
| 11 | Product English sealed (no `_Inferred`) | wishful RTTI | **Fails (open)** — no type name recovered |
| 12 | Runtime Confirmed | wave seal claim | **Fails (open)** — no Launcher; dual CF seal only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| thiscall RET 4 / ECX=dest / stack=src | **High** | Corrupt every construct/copy site |
| Exactly 0x40 / 16 dwords | **High** | Truncate or overrun query +0x80..+0xBF |
| Leaf / no callees | **High** | Invented side effects |
| EAX = dest return | **High** | Wrong if any consumer uses EAX |
| Shared utility (multi-family) | **High** | Over-narrow naming |
| Product blob English | **Low–Med** | Doc only (`_Inferred`) |
| Runtime | **Open** | Not claimed |

---

## 3. Cross-check against raw ≡ live

```text
// sealed CF (assembly)
dest = ECX
src  = [ESP+4]
EAX  = dest                    // preserved through body
for i in 0..15:
  dest[i] = src[i]             // dword stores; last uses ECX temp for +0x3C
return dest                    // EAX; RET 4
// size 103 B (0x005eb040..0x005eb0a6); pad CC after
```

Parent contrast (evidence only; dualled R11-008):

* `FUN_005eb210` — base query ctor; tail `LEA ECX,[ESI+0x80]; PUSH params+0x20; CALL 005eb040`.
* Nearby `FUN_005eb0b0` / `FUN_005eb0e0` — also call this for 0x40 blocks (not dualled here).
* Vector PodCopy leaves (`00409f70` etc.) — different ABI/size family; **do not merge**.

Bytes seal (`read_memory`):

```text
8B C1 8B 4C 24 04 8B 11 89 10 … 8B 49 3C 89 48 3C C2 04 00 CC…
```

---

## 4. Surviving contract for AutoCore

```
PodCopyBlock_0x40_Thiscall_Inferred(dest, src):
  // thiscall: ECX=dest, stack=src*, RET 4, EAX=dest
  copy 16 dwords (0x40 bytes) src -> dest
  no null check, no overlap handling, no calls
```

**Port tests:**

* After `005eb210` construct: `self[+0x80 .. +0xBF]` equals `params[+0x20 .. +0x5F]`.
* Implement as unrolled 16×`uint32` stores or `memcpy(dest, src, 0x40)` with **thiscall RET 4**.
* Do **not** treat as query ctor, vector element PodCopy, or debug-stop helper.
* Do **not** trust decompiler `void` — EAX is dest.
* Do **not** invent product matrix/transform labels without further caller duals.

**Verdict:** **accept-with-gaps** — adversarial scaffold / ctor-merge / vector-PodCopy-merge / wrong-ABI / wrong-size / void-return claims **all falsified**. Product blob English and runtime remain open (terminal false).
