# Review B (skeptical / adversarial): `aa_0094a6a0` Client_InitInstance

| Field | Value |
|---|---|
| **Stable ID** | `aa_0094a6a0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0094a6a0_Client_InitInstance.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | "Just clonebase / table batch" | Entry banner + render/physics/sound/UI phases; tables only when `+0x31f5==0` | **Falsified exclusive role** |
| 2 | cdecl / thiscall | Exit **`RET 4`**; arg on stack; not ECX-only | **`__stdcall` stands** |
| 3 | Returns void / 0 on success | `mov eax,1` success; caller tests nonzero | **return 1 sealed** |
| 4 | Always loads all data tables | Three gates on `+0x31f5` skip batch | **Gated — keep** |
| 5 | Multiple entry callers | Single xref `FUN_0094ba40` | **Sole static caller** |
| 6 | Graphics fail returns error code | `_exit(1)` non-returning | **Hard exit stands** |
| 7 | Named only from scaffold guess | `"Client InitInstance"` / `"InitInstance::done"` live strings | **Name High** |
| 8 | Server needs this unit | Pure client Win32 boot | **No server port requirement** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| stdcall 1-arg | **High** | Wrong ABI / stack imbalance |
| Phase order | **High** | Wrong boot sequencing |
| Gate +0x31f5 | **High** | Wrong light-boot behavior |
| Product name | **High** | Doc only |
| Manager type names | **Tentative** | Doc / future renames |
| `-developer` only entry | **Medium** | Residual on **caller** not this VA |

---

## 3. Cross-check against raw / bytes

```
raw ≡ live decompile (no CF delta)
entry: 55 8B EC 6A FF 68 … SEH
work:  mov edi,[ebp+8] client
exit:  mov eax,1; …; ret 4
strings: Client InitInstance → InitInstance::done
gate:  cmp byte [app+0x31f5],0 at post-init / tables / generators
```

Reject renames that drop InitInstance product identity. Reject "table-only" summaries as complete purpose. Keep dual ensure calls as written (no CSE of distant helpers).

---

## 4. Surviving contract for AutoCore

```
// Client-only. Do not invent a Sector InitInstance mirror without separate evidence.

uint32_t Client_InitInstance(ClientApp* app):  // stdcall
  // fixed phase order (see raw phase map)
  // if graphics init fails: _exit(1)
  // if app->flag_31f5 == 0:
  //   ensure XP/credits/loot/medal tables; InitGenerators; extra asset post-init
  // always: clonebase lists, physics, sound, UI, QPC stamps
  return 1

// Caller (context only):
//   if (Client_InitInstance(&g_ClientApp) != 0) enter main loop path
```

Port relevance: **documentation / client RE only** unless AutoCore grows a matching client shell.

---

## 5. Open questions

1. Class name of client app singleton.
2. Product English for `+0x31f5`.
3. Whether non-`-developer` entry uses a twin InitInstance (search residual outside this VA).
4. Live boot log vs phase banners order.

**Verdict:** **accept-with-gaps** — adversarial kills table-only and wrong-ABI misreads; InitInstance orchestration stands.
