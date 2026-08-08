# Review B (skeptical / adversarial): `aa_007b5be0` CNDUIWindow_CompleteDtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_007b5be0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY WQ9K-F) |
| **Counterpart** | `reviews/A_aa_007b5be0_CNDUIWindow_CompleteDtor.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is only a scalar-deleting dtor | **Falsified** — no flags arg; installs vtbl; large free chain + base; no free of `this` |
| 2 | This is a vector-deleting dtor | **Falsified** — no array count / no host `operator_delete[]` |
| 3 | cdecl / stack this | **Falsified** — entry `MOV ESI,ECX` |
| 4 | Frees host heap | **Falsified** — bare `RET`; host free is scalar peer `0x00423e50` only |
| 5 | `operator_delete` is noreturn / truncates body | **Falsified** — disasm continues free chain, nested CS, `FUN_00759de0`, `RET` |
| 6 | Product name is VOG_DEBUG_STOP helper only | **Falsified** — RTTI type_info **`.?AVCNDUIWindow@@`**; strings are debug side-path |
| 7 | Same class as CNDUIWndBuffered | **Falsified** — different vtbl `00a960ac` vs `00a99f74`; buffered *calls* this as base |
| 8 | Same as CWndWaypointIcon complete | **Falsified** — waypoint installs `00a7000c` then calls this |
| 9 | Always skips free of owned slots | **Falsified** — each slot has null-check free then always-null store |
| 10 | Live counter is incremented here | **Falsified** — `SUB [DAT_00d17954],1`; ctor increments |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Complete vs scalar/vector | **High** | Double-free / miss free |
| Vtbl + RTTI product name | **High** | Naming residual closed |
| Free-then-null order | **High** | Leak / UAF |
| False-noreturn correction | **High** | Truncated port |
| Helper / slot product English | **Open** | Residual only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + vtbl

```
// FUN_007b5be0 (CNDUIWindow complete):
// SEH; ESI = ECX
mov  dword ptr [ESI], 00a960ach
; owner debug if [ESI+2B0h]
sub  dword ptr [00d17954h], 1
; optional child vcall +0xC
call FUN_007a8580 / 007aec70 / 007aff00
; free many owned ptrs (delete / delete[])
; nested +0x1E8 dual 00424060 + DeleteCriticalSection
call FUN_00759de0
; SEH restore; ret
```

Live decompile 2026-08-05 ≡ raw CF with noreturn warning corrected by full disasm.  
`read_memory` COL `@0x00a960a8` → `0x00ab75c8` → type_info `0x00afe1ac` → `.?AVCNDUIWindow@@`.  
vtbl[0] dword `@0x00a960ac` = `0x00423e50` (scalar peer).

---

## 4. Surviving contract for AutoCore

```
// Port complete dtor only (not scalar):
void CNDUIWindow_CompleteDtor(void* self) {
  *(void**)self = &PTR_FUN_00a960ac;
  // optional owner-debug path on +0x2B0
  g_liveWindowCount--;
  // release child +0x2B4 if flag +0xBD
  // shared teardown helpers
  // free owned heap slots (always null after)
  // nested CS object @ +0x1E8
  FUN_00759de0(self); // super-base
}
// Do NOT operator_delete(self) here.
// Scalar peer: 0x00423e50
// Ctor twin: 0x007b5dd0 (same vtbl)
```

---

## 5. Verdict

**accept-with-gaps** — adversarial probes on role/ABI/vtbl/RTTI/free-path/false-noreturn falsified; helper/slot English remains open. Terminal **false**.
