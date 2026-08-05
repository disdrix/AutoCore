# Review B (skeptical / adversarial): `aa_00946c00` `Client_DispatchUiEventQueue`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00946c00` |
| **VA** | `0x00946c00` |
| **Canonical name** | `Client_DispatchUiEventQueue` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00946c00_Client_DispatchUiEventQueue.md` |
| **System** | `missions-progression` / client UI tick |
| **Live tools** | Ghidra `decompile_function` + `read_memory` only |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | This is a physics/steer tick | Callees are UI/mission/chrome; steer only as park zero on some cases | **Falsified** as physics core |
| 2 | `__stdcall` / stack client | Prologue `mov ebx,ecx`; sole caller passes ECX | **Falsified** stdcall |
| 3 | Switch on float physics values | Cases are denormal float **bit patterns of small ints** (type ids) | **Falsified** as float physics switch |
| 4 | Always runs full switch | Focus gate sends alternate type-`0x1e` scan path | **Falsified** always-full |
| 5 | Multiple static callers | xrefs: only `FUN_0094b520` | **Attack fails** — sole caller sealed |
| 6 | Scaffold invents case set | Live decompile ≡ 2026-07-23 raw | **Attack fails** |
| 7 | Product enum proven | Structural only; strings seal a few arms | **Agree Open** |
| 8 | Queue element size free-form | `/0x138` count + `pfVar15 += 0x4e` (0x138 B) | **Attack fails** — stride sealed |
| 9 | `VehicleEntity_SetHandbrake` means drive-control ownership | Only conditional park on selected types when `+0x250` vehicle present | **Falsified** as drive tick |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Fastcall client ECX | **Confirmed** | Wrong this in port |
| Queue @`e04→e8bc/e8c0` stride `0x138` | **Confirmed** | Miss/drop events |
| Type `@+0x1c` int ids | **Confirmed** | Mis-dispatch arms |
| Dual gate (full vs 0x1e scan) | **Confirmed** | Stuck dialog path |
| Product case names | **Open** | Docs only |
| Every arm semantic | **Partial** | Porting individual UI features |

---

## 3. Cross-check against raw / live / prologue

Live decompile matches raw: SEH, session gate, `FUN_007a69d0`, dual branch, `do { switch(pfVar15[7]); pfVar15 += 0x4e; }`, `FUN_00406840`, alternate `*(iVar14+0x1c)==0x1e`.

Prologue bytes confirm `and esp,-8`, SEH `LAB_009bba67`, `chkstk` budget `0x1A14`, `mov ebx,ecx`, load `[ebx+0xe04]` then `[eax+0xe8bc]`.

**Trap:** treating denormal `case 1.4013e-45` as a float threshold — it is **type id 1**. Ports must switch on **integer** type field.

**Trap:** assuming this function implements mission objective logic — it only **dispatches UI side effects** from a pre-queued event list filled elsewhere.

---

## 4. Surviving contract for AutoCore

```text
// Client frame (after peer helper FUN_00944770):
Client_DispatchUiEventQueue(client):
  session = client.session_e04
  if !session or empty(session.uiEventQueue_e8bc): return
  if !missionFocusLocked(client):   // f40/f38/c78 gate
      for e in session.uiEventQueue:  // stride 0x138
          dispatch_ui_event(client, e)  // switch e.type@+0x1c
      clear_queue_helper()              // FUN_00406840
  else:
      if find type==0x1e: special(FUN_009430f0)
```

Server AutoCore does **not** need this client dispatcher for wire correctness; useful for client-parity UI automation and understanding which sector opcodes (`0x207a`, `0x20bf`) and chrome flags (`DAT_00d17928..2a`) fire from which event types.

---

## 5. Open questions

1. Product name of event type enum and queue owner class.
2. Who enqueues records into `+0xe8bc` (not OWN).
3. Full mapping type id → English UI action for all ~40 cases.
4. Runtime multi-event ordering golden.

**Verdict:** **accept-with-gaps**
