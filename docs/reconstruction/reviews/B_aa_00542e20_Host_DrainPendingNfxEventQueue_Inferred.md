# Review B (skeptical / adversarial): `aa_00542e20` Host_DrainPendingNfxEventQueue_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00542e20` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W35-F) |
| **Counterpart** | `reviews/A_aa_00542e20_Host_DrainPendingNfxEventQueue_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Pure `__fastcall` one-arg void | **Falsified** — **RET 4** + caller push; ECX + stack |
| 2 | Host is session field `*(+0xe4e8)` only (AppFrameTick clean) | **Falsified** — call site loads **ECX=`DAT_00b041fc`**, pushes session field |
| 3 | Scaffold product name `Named_nfx_*` | **Reject** — string is path filter only |
| 4 | Always deletes every node | **Falsified** — bound path reloads NFX and keeps processing without mandatory delete |
| 5 | operator_delete never returns | **Falsified** — decompiler warning; loop continues |
| 6 | Host is definitively "GameData" | **Careful** — same global as LookupCloneBase host; large offsets; keep **Host_** structural plate |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ECX host + RET 4 | **High** | Wrong frame-tick port |
| Queue offsets f28/f2c/f0c | **High** | Wrong host layout |
| Three-way branch semantics | **High** | Missed FX fire/reload |
| Stack arg meaning | **Low** | Dead vs latent use |
| Product English | **Low–Med** | Naming |
| Runtime | **Open** | Matrix |

---

## 3. Cross-check against raw + bytes + caller

Caller `FUN_0094b520` bytes:

```
mov eax, [edi+0xe04]
test eax, eax
jz skip
mov edx, [eax+0xe4e8]
mov ecx, [DAT_00b041fc]
push edx
call 0x00542e20
```

Matches dual-arg ABI. Body uses EBX=ECX for `+0xf2c` gate and list walk.

Callee cross-links: `FUN_004a6390` (LoadMasterFromXML), `FUN_0043d650` (ResizeZeroFill 0), `Object_ResolveFromTFID` — consistent with pending FX/event processing, not a trivial stub.

---

## 4. Surviving contract for AutoCore

```
// Port with ECX host + ignored-or-opaque stack arg:
void DrainPendingNfxEventQueue(Host* host /*ECX*/, void* sessionField /*stack*/) {
  while (host->pendingCount) {
    auto* n = host->pendingList.front;
    if (!TryReady(n->ring, ...)) break;
    auto* row = host->map.lookup(n->key);
    if (!row) { unlink_delete(n); continue; }
    if (!n->bound) { bind_or_drop_and_fire(n); continue; }
    maybe_reload_nfx_master(n);
    reset_node_state(n);
  }
  // finish ring if needed
}
// Fix Client_AppFrameTick clean to pass global host in ECX.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI, host offsets, branch structure, NFX reload, sole caller. Residual stack-arg semantics + product host English → **accept-with-gaps**.
