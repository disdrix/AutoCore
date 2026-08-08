# Review B (skeptical / adversarial): `aa_004cb680` SkillCNDHash_ReleaseChainsToFreelist_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cb680` |
| **VA** | `0x004cb680` |
| **Canonical name** | `SkillCNDHash_ReleaseChainsToFreelist_Inferred` |
| **Review date** | `2026-08-04` (WQ9F-A dual) |
| **Reviewer role** | Skeptical / adversarial (Path B) |
| **Counterpart** | `reviews/A_aa_004cb680_SkillCNDHash_ReleaseChainsToFreelist_Inferred.md` |
| **Live tools** | Independent `batch_decompile` + `read_memory` + callers |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Custom EAX ABI (inventory freelist style) | **Falsified** — entry `mov ebx,ecx`; bare `ret` |
| 2 | Frees table / slab itself | **Falsified** — only walks chains + freelist; table free is parent `004cba60` |
| 3 | `operator_delete` is noreturn / whole body dead after first payload | **Falsified** — post-call `add esp,4`; continues freelist push + loop |
| 4 | Loop is `i < mask` (excludes last bucket) | **Falsified** — `jbe` / `uVar4 <= mask` = inclusive |
| 5 | Stamp `009cb968` is permanent freelist marker | **Falsified** — immediately overwritten by freelist next at `*node` |
| 6 | Zeros live count / mask | **Falsified** — no writes to `+0x0c` / `+0x08`; parent zeros count |
| 7 | Multiple direct callers | **Falsified** — sole xref `004cba6a` from destroy |
| 8 | Product class English sealed | **Fails** — role High; English `_Inferred` |
| 9 | Bit-exact / runtime Confirmed | **Fails** — open; no Launcher |

---

## 2. Decisive machine dataflow

```text
// entry
EBX = ECX (hash)
ECX = 0; EBP = 0          // index=0
loop:
  EAX = [EBX+0x10]        // table
  EDX = [EAX+EBP*4]       // bucket*
  EDI = [EDX+4]           // chain head
  if EDI==0: goto clear_head
  body:
    ESI = EDI
    EDI = [EDI+0xc]       // next
    [ESI] = 009cb968
    if [ESI+8]!=0: push; call operator_delete; add esp,4
    [ESI+8] = 0
    [ESI] = [EBX+0x20]; [EBX+0x20] = ESI
    if EDI!=0: body
  clear_head:
    [bucket+4] = 0
    EBP++
    if EBP <= [EBX+8]: loop
  pop edi,esi,ebp,ebx; ret
```

A ≡ B on live decompile + entry/exit. Prior WQ9E-A residual correctly left this nested helper open; CF sealed here.

---

## 3. Confidence (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Freelist-release CF | **High** | Leak / double-free on skill hash recreate |
| thiscall / bare ret | **High** | Wrong calling convention |
| mask-inclusive walk | **High** | Last bucket leak |
| payload @ +8 / next @ +0xc | **High** | Wrong node layout |
| Product English | **Open** | Naming only |
| Freelist consumer dual | **Open** | Pop path residual |

---

## 4. Surviving contract

- **thiscall ECX=hash**, void, bare ret.
- For each bucket `0..mask`: drain chain from `bucket+4`; delete payload `@+8`; push nodes to freelist `@+0x20`; null head.
- Temp vtbl stamp `009cb968` is not retained on freelist nodes.
- **Terminal false** (no runtime Confirmed).

**Verdict:** **accept-with-gaps**
