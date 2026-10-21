:root {
  --red: #bd3038;
  --red-dark: #a9252e;
  --red-soft: #fcf1f2;
  --ink: #292929;
  --muted: #777;
  --line: #dedede;
  --green: #21a638;
  --bg: #f6f6f6;
}

* {
  box-sizing: border-box;
}

html,
body {
  margin: 0;
  min-height: 100%;
  font-family: Arial, Helvetica, sans-serif;
  color: var(--ink);
  background: var(--bg);
  font-size: 14px;
}

button,
input,
select {
  font: inherit;
}

button {
  cursor: pointer;
}

[hidden] {
  display: none !important;
}

.site-shell {
  min-height: 100vh;
  display: flex;
  flex-direction: column;
}

.site-header {
  height: 78px;
  background: #fff;
  border-bottom: 1px solid #e5e5e5;
  display: flex;
  align-items: center;
  justify-content: space-between;
  padding: 0 clamp(24px, 5vw, 76px);
  gap: 30px;
}

.brand {
  display: flex;
  align-items: center;
  gap: 12px;
  color: #272f70;
}

.site-logo {
  height: 52px;
  width: auto;
  max-width: 100%;
  object-fit: contain;
  display: block;
}

.seal {
  height: 49px;
  width: 49px;
  border: 2px solid #333c80;
  border-radius: 50%;
  display: grid;
  place-items: center;
  text-align: center;
  font: 700 7px Georgia, serif;
  position: relative;
  flex-shrink: 0;
}

.seal:after {
  content: "";
  position: absolute;
  inset: 4px;
  border: 1px solid #333c80;
  border-radius: 50%;
}

.brand-wordmark {
  min-width: 0;
}

.brand-vit {
  font: 700 36px/0.85 Georgia, serif;
  letter-spacing: -2px;
  text-align: center;
}

.brand-rule {
  height: 2px;
  background: #303779;
  margin: 4px 0 3px;
}

.brand-name {
  font: 700 11px Georgia, serif;
  white-space: nowrap;
}

.brand-caption {
  font: 7px Georgia, serif;
  color: #555;
  white-space: nowrap;
}

.header-right {
  display: flex;
  align-items: center;
  gap: 22px;
}

.header-label {
  font-size: 13px;
  color: #666;
}

.user-chip-wrapper {
  position: relative;
}

.user-chip {
  display: flex;
  align-items: center;
  gap: 10px;
  border-left: 1px solid #e5e5e5;
  padding-left: 22px;
  background: transparent;
  border-top: 0;
  border-right: 0;
  border-bottom: 0;
  cursor: pointer;
  text-align: left;
  border-radius: 6px;
  padding-top: 5px;
  padding-bottom: 5px;
  padding-right: 8px;
  transition: background 0.15s ease;
}

.user-chip:hover {
  background: #f7f7f7;
}

.dropdown-chevron {
  width: 14px;
  height: 14px;
  stroke: #888;
  fill: none;
  stroke-width: 2;
  stroke-linecap: round;
  stroke-linejoin: round;
  transition: transform 0.2s ease;
  margin-left: 2px;
  flex-shrink: 0;
}

.user-chip[aria-expanded="true"] .dropdown-chevron {
  transform: rotate(180deg);
}

.user-menu-popup {
  position: absolute;
  top: calc(100% + 8px);
  right: 0;
  background: #ffffff;
  border: 1px solid #e5e5e5;
  border-radius: 8px;
  box-shadow: 0 8px 24px rgba(0, 0, 0, 0.12);
  min-width: 220px;
  z-index: 200;
  padding: 8px;
  display: flex;
  flex-direction: column;
  gap: 4px;
  animation: popupFadeIn 0.15s ease-out;
}

@keyframes popupFadeIn {
  from {
    opacity: 0;
    transform: translateY(-6px);
  }
  to {
    opacity: 1;
    transform: translateY(0);
  }
}

.popup-user-info {
  padding: 8px 10px 8px;
  border-bottom: 1px solid #f0f0f0;
  margin-bottom: 4px;
}

.popup-user-name {
  font-weight: 700;
  font-size: 13px;
  color: var(--ink);
}

.popup-user-program {
  font-size: 11px;
  color: #777;
  margin-top: 2px;
  line-height: 1.4;
}

.popup-logout-btn {
  display: flex;
  align-items: center;
  gap: 10px;
  width: 100%;
  padding: 9px 12px;
  border: 0;
  border-radius: 6px;
  background: transparent;
  color: var(--red);
  font-size: 13px;
  font-weight: 600;
  cursor: pointer;
  text-align: left;
  transition: background 0.15s ease;
}

.popup-logout-btn:hover {
  background: var(--red-soft);
}

.popup-logout-btn svg {
  width: 17px;
  height: 17px;
  stroke: currentColor;
  fill: none;
  stroke-width: 2;
  stroke-linecap: round;
  stroke-linejoin: round;
}

.avatar {
  height: 38px;
  width: 38px;
  border-radius: 50%;
  display: grid;
  place-items: center;
  background: var(--red-soft);
  color: var(--red);
  font-weight: 700;
}

.user-name {
  font-weight: 600;
  font-size: 13px;
}

.user-program {
  font-size: 11px;
  color: #888;
  margin-top: 3px;
}

.login-layout {
  flex: 1;
  display: grid;
  grid-template-columns: minmax(300px, 1fr) minmax(390px, 470px);
  align-items: stretch;
  background: #fff;
}

.login-brand-panel {
  padding: clamp(40px, 7vw, 100px);
  display: flex;
  flex-direction: column;
  justify-content: center;
  align-items: flex-start;
  background: #fff;
  border-right: 1px solid #eee;
}

.large-brand {
  width: min(100%, 420px);
  color: #272f70;
  display: flex;
  align-items: center;
  margin-bottom: 35px;
}

.large-logo {
  width: 100%;
  max-width: 340px;
  height: auto;
  object-fit: contain;
  display: block;
}

.large-seal {
  width: 94px;
  height: 94px;
  border: 2px solid #333c80;
  border-radius: 50%;
  display: grid;
  place-items: center;
  text-align: center;
  font: 700 10px Georgia, serif;
  position: relative;
  flex-shrink: 0;
  margin-right: 10px;
}

.large-seal:after {
  content: "";
  position: absolute;
  inset: 6px;
  border: 1px solid #333c80;
  border-radius: 50%;
}

.large-wordmark {
  flex: 1;
}

.large-vit {
  font: 700 67px/0.88 Georgia, serif;
  letter-spacing: -4px;
  text-align: center;
}

.large-rule {
  height: 2px;
  background: #303779;
  margin: 5px 0 4px;
}

.large-name {
  font: 700 16px Georgia, serif;
  white-space: nowrap;
}

.large-caption {
  font: 9px Georgia, serif;
  color: #555;
  white-space: nowrap;
}

.script-title {
  font-family: "Brush Script MT", "Segoe Script", cursive;
  font-size: clamp(29px, 3vw, 42px);
  font-style: italic;
  margin: 0 0 20px;
  color: #292929;
}

.brand-message {
  max-width: 480px;
  font: 17px/1.8 Georgia, serif;
  color: #777;
}

.brand-accent {
  height: 4px;
  width: 70px;
  background: var(--red);
  margin-top: 28px;
}

.login-side {
  background: #fafafa;
  display: flex;
  align-items: center;
  justify-content: center;
  padding: 55px 45px;
}

.login-card {
  width: 100%;
  max-width: 390px;
  background: #fff;
  border: 1px solid #e5e5e5;
  border-radius: 7px;
  padding: 35px;
  box-shadow: 0 7px 25px #00000005;
}

.login-card h1 {
  font: 700 26px Georgia, serif;
  margin: 0 0 9px;
}

.login-card .subtext {
  color: #777;
  margin: 0 0 28px;
  font: 15px Georgia, serif;
}

.field-label {
  display: block;
  font: 700 15px Georgia, serif;
  margin: 0 0 9px;
}

.text-input {
  height: 45px;
  width: 100%;
  padding: 0 12px;
  border: 1px solid #ddd;
  border-radius: 4px;
  background: #fff;
  margin-bottom: 22px;
  outline-color: #1686ff;
}

.primary {
  border: 0;
  border-radius: 4px;
  background: var(--red);
  color: #fff;
  font-weight: 600;
  padding: 13px 18px;
  font-size: 13px;
}

.primary:hover {
  background: var(--red-dark);
}

.full {
  width: 100%;
}

.error {
  font-size: 12px;
  color: var(--red);
  margin-top: 10px;
}

.portal-layout {
  min-height: calc(100vh - 78px);
  display: grid;
  grid-template-columns: 235px minmax(0, 1fr);
}

.sidebar {
  background: #fff;
  border-right: 1px solid #e3e3e3;
  padding: 28px 16px;
  display: flex;
  flex-direction: column;
  gap: 5px;
}

.sidebar-label {
  text-transform: uppercase;
  letter-spacing: 1.2px;
  font-size: 10px;
  font-weight: 700;
  color: #aaa;
  padding: 0 14px;
  margin: 0 0 12px;
}

.side-link {
  display: flex;
  align-items: center;
  gap: 13px;
  width: 100%;
  padding: 13px 14px;
  border: 0;
  border-radius: 5px;
  background: transparent;
  text-align: left;
  color: #666;
  font-size: 13px;
}

.side-link svg {
  width: 19px;
  height: 19px;
  stroke: currentColor;
  fill: none;
  stroke-width: 1.7;
  stroke-linecap: round;
  stroke-linejoin: round;
}

.side-link.active {
  background: var(--red-soft);
  color: var(--red);
  font-weight: 600;
}

.side-link:hover:not(.active) {
  background: #f7f7f7;
}

.nav-badge {
  margin-left: auto;
  color: var(--red);
  font-size: 11px;
  font-weight: 700;
}

.content-area {
  padding: 32px clamp(22px, 4vw, 58px) 55px;
  min-width: 0;
}

.content-top {
  display: flex;
  justify-content: space-between;
  align-items: flex-start;
  gap: 20px;
  margin-bottom: 25px;
}

.page-heading {
  font: 700 27px Georgia, serif;
  margin: 0 0 7px;
}

.page-description {
  color: #777;
  font-size: 13px;
  margin: 0;
}

.date-label {
  font-size: 12px;
  color: #888;
  background: #fff;
  border: 1px solid #e5e5e5;
  padding: 10px 13px;
  border-radius: 4px;
  white-space: nowrap;
}

.hello {
  font: 700 25px Georgia, serif;
  margin: 0 0 6px;
}

.subtitle {
  font-size: 14px;
  color: #555;
  margin-bottom: 25px;
}

.dashboard-grid {
  display: grid;
  grid-template-columns: minmax(0, 1.5fr) minmax(260px, 1fr);
  gap: 20px;
  align-items: start;
}

.tip {
  border: 1px solid #ead9da;
  background: var(--red-soft);
  border-radius: 6px;
  padding: 20px;
  margin-bottom: 20px;
}

.eyebrow {
  font-size: 12px;
  color: #c51f2b;
  font-weight: 600;
  margin-bottom: 11px;
}

.muted {
  font-size: 12px;
  color: #808080;
}

.tip-title {
  font-size: 14px;
  font-weight: 600;
  margin: 8px 0;
}

.link {
  border: 0;
  padding: 0;
  background: none;
  color: #d01f2a;
  font-size: 12px;
  text-align: left;
}

.tip .link {
  margin-top: 12px;
}

.card {
  background: #fff;
  border: 1px solid var(--line);
  border-radius: 6px;
  padding: 20px;
}

.card-title {
  font-size: 15px;
  font-weight: 650;
  margin: 0 0 17px;
}

.stat-grid {
  display: grid;
  grid-template-columns: 1fr 1fr;
  gap: 15px;
  margin-bottom: 20px;
}

.stat-label {
  font-size: 12px;
  color: #777;
  margin-bottom: 12px;
}

.stat-number {
  font-size: 29px;
  line-height: 1;
  color: var(--red);
  margin-bottom: 10px;
}

.stat-strong {
  font-weight: 600;
  font-size: 14px;
  margin-bottom: 9px;
}

.stat-foot {
  font-size: 12px;
  color: #888;
  margin-bottom: 12px;
}

.section-heading {
  display: flex;
  align-items: center;
  justify-content: space-between;
  gap: 12px;
  margin: 0 0 14px;
}

.section-heading h2 {
  font-size: 16px;
  font-weight: 650;
  margin: 0;
}

.panel {
  border: 1px solid var(--line);
  border-radius: 6px;
  padding: 17px;
  background: #fff;
}

.class-row {
  display: grid;
  grid-template-columns: 65px 1fr;
  gap: 12px;
  padding: 3px 0 15px;
}

.class-row + .class-row {
  border-top: 1px solid #e2e2e2;
  padding-top: 15px;
  padding-bottom: 0;
}

.time {
  font-size: 12px;
  color: #888;
  padding-top: 2px;
}

.class-name {
  font-size: 14px;
  font-weight: 600;
  margin-bottom: 5px;
}

.class-meta {
  font-size: 12px;
  color: #888;
}

.course-grid {
  display: grid;
  grid-template-columns: repeat(2, minmax(0, 1fr));
  gap: 20px;
}

.course-title {
  font: 700 21px Georgia, serif;
  margin: 0 0 5px;
}

.course-code {
  margin: 0 0 17px;
  color: #555;
}

.attendance-card {
  border: 1px solid var(--line);
  border-radius: 6px;
  padding: 19px;
  margin-bottom: 0;
  background: #fff;
}

.attendance-head {
  display: flex;
  justify-content: space-between;
  align-items: center;
  gap: 10px;
  font-size: 13px;
  font-weight: 600;
  margin-bottom: 12px;
}

.attendance-score {
  font-size: 28px;
  color: var(--red);
  line-height: 1.1;
}

.attendance-score.good {
  color: var(--green);
}

.progress {
  height: 5px;
  background: #f0f0f0;
  margin: 11px 0 13px;
  overflow: hidden;
}

.progress span {
  display: block;
  height: 100%;
  background: var(--red);
}

.progress span.good {
  background: var(--green);
}

.status-note {
  font-size: 12px;
  color: #ff1e2d;
}

.status-note.good {
  color: #1eaf31;
}

.attendance-footer {
  margin-top: 15px;
  padding-top: 14px;
  border-top: 1px solid #eee;
  display: flex;
  justify-content: space-between;
  align-items: center;
  gap: 8px;
}

.attendance-footer span {
  font-size: 11px;
  color: #888;
}

.upload-layout {
  display: grid;
  grid-template-columns: minmax(0, 1fr) minmax(260px, 0.7fr);
  gap: 22px;
  align-items: start;
}

.upload-form .field-label {
  margin-top: 22px;
}

.upload-form .field-label:first-child {
  margin-top: 0;
}

.select {
  height: 47px;
  width: 100%;
  border: 1px solid var(--line);
  border-radius: 4px;
  padding: 0 12px;
  background: #fff;
  color: #555;
}

.file-drop {
  margin-top: 9px;
  background: #f7f7f7;
  border: 1px dashed #d8d8d8;
  border-radius: 5px;
  padding: 26px;
  text-align: center;
}

.upload-symbol {
  font-size: 29px;
  color: #888;
  margin-bottom: 14px;
}

.file-choose {
  height: 43px;
  border: 1px solid #dedede;
  border-radius: 4px;
  background: white;
  width: 100%;
  font-weight: 600;
}

.file-hint {
  font-size: 11px;
  color: #888;
  margin-top: 12px;
  text-align: left;
}

.upload-submit {
  margin-top: 24px;
}

.helper-list {
  list-style: none;
  padding: 0;
  margin: 0;
}

.helper-list li {
  font-size: 12px;
  color: #777;
  line-height: 1.7;
  padding: 12px 0;
  border-bottom: 1px solid #eee;
}

.helper-list li:last-child {
  border: 0;
}

.helper-list strong {
  color: #333;
  display: block;
  font-size: 13px;
  margin-bottom: 3px;
}

.notification-list {
  max-width: 900px;
}

.notification {
  display: grid;
  grid-template-columns: 28px 1fr auto;
  gap: 14px;
  align-items: start;
  border: 1px solid var(--line);
  border-radius: 6px;
  padding: 19px;
  margin-bottom: 15px;
  background: #fff;
}

.notification svg {
  width: 21px;
  height: 21px;
  stroke: #777;
  fill: none;
  stroke-width: 1.7;
  stroke-linecap: round;
  stroke-linejoin: round;
}

.notification-title {
  font-size: 14px;
  font-weight: 600;
  margin-bottom: 8px;
}

.notification .muted {
  margin-bottom: 7px;
}

.notification .muted:last-child {
  margin-bottom: 0;
}

.notification-time {
  font-size: 11px;
  color: #999;
  white-space: nowrap;
}

.assignment-list {
  display: grid;
  grid-template-columns: repeat(2, minmax(0, 1fr));
  gap: 17px;
}

.assignment-card .class-name {
  font-size: 15px;
  margin-bottom: 8px;
}

.assignment-card .class-meta {
  line-height: 1.6;
}

.assignment-card .primary {
  margin-top: 18px;
}

.toast {
  display: none;
  position: fixed;
  z-index: 30;
  right: 28px;
  bottom: 26px;
  background: #292929;
  color: #fff;
  padding: 14px 18px;
  border-radius: 5px;
  max-width: 360px;
  font-size: 13px;
  box-shadow: 0 4px 16px #0002;
}

@media (max-width: 1000px) {
  .login-layout {
    grid-template-columns: 1fr 420px;
  }
  .login-brand-panel {
    padding: 45px;
  }
  .portal-layout {
    grid-template-columns: 205px minmax(0, 1fr);
  }
  .dashboard-grid,
  .upload-layout {
    grid-template-columns: 1fr;
  }
  .course-grid {
    grid-template-columns: 1fr 1fr;
  }
  .content-area {
    padding: 28px 24px 45px;
  }
}

@media (max-width: 720px) {
  .site-header {
    padding: 0 18px;
    height: 68px;
  }
  .header-label,
  .user-program {
    display: none;
  }
  .brand {
    min-width: 0;
  }
  .site-logo {
    height: 42px;
  }
  .large-logo {
    max-width: 260px;
  }
  .brand-vit {
    font-size: 29px;
  }
  .seal {
    height: 40px;
    width: 40px;
  }
  .brand-name {
    font-size: 9px;
  }
  .brand-caption {
    font-size: 6px;
  }
  .user-chip {
    padding-left: 8px;
    padding-right: 6px;
    gap: 6px;
    border-left: 0;
  }
  .user-menu-popup {
    right: 0;
    top: calc(100% + 6px);
    min-width: 190px;
  }
  .avatar {
    width: 32px;
    height: 32px;
  }
  .portal-layout {
    display: block;
  }
  .sidebar {
    position: fixed;
    bottom: 0;
    left: 0;
    right: 0;
    z-index: 100;
    background: #ffffff;
    border-top: 1px solid #e5e5e5;
    border-right: 0;
    border-bottom: 0;
    padding: 6px 8px;
    padding-bottom: calc(6px + env(safe-area-inset-bottom, 0px));
    display: flex;
    flex-direction: row;
    justify-content: space-around;
    align-items: center;
    gap: 4px;
    box-shadow: 0 -3px 12px rgba(0, 0, 0, 0.08);
  }
  .sidebar-label {
    display: none;
  }
  .side-link {
    display: flex;
    justify-content: center;
    align-items: center;
    flex: 1;
    height: 48px;
    padding: 0;
    border-radius: 8px;
    position: relative;
    white-space: nowrap;
    background: transparent;
  }
  .side-link svg {
    width: 22px;
    height: 22px;
  }
  .side-link .link-label {
    display: none;
  }
  .side-link .nav-badge {
    position: absolute;
    top: 6px;
    right: calc(50% - 15px);
    background: var(--red);
    color: #fff;
    font-size: 9px;
    font-weight: 700;
    height: 15px;
    min-width: 15px;
    line-height: 15px;
    border-radius: 10px;
    text-align: center;
    padding: 0 4px;
    margin-left: 0;
  }
  .content-area {
    padding: 22px 18px 85px;
  }
  .content-top {
    align-items: flex-start;
  }
  .page-heading {
    font-size: 24px;
  }
  .course-grid,
  .assignment-list {
    grid-template-columns: 1fr;
  }
  .login-layout {
    display: block;
  }
  .login-brand-panel {
    display: none;
  }
  .login-side {
    min-height: calc(100vh - 68px);
    padding: 25px 18px;
  }
  .login-card {
    padding: 28px 24px;
    box-shadow: none;
  }
  .stat-grid {
    gap: 10px;
  }
  .card {
    padding: 16px;
  }
  .notification {
    grid-template-columns: 23px 1fr;
    gap: 10px;
    padding: 15px;
  }
  .notification-time {
    grid-column: 2;
  }
  .date-label {
    display: none;
  }
  .toast {
    bottom: 74px;
    right: 16px;
    left: 16px;
    max-width: none;
  }
}
