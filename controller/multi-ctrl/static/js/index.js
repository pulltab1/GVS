$(() => {
  $('#open-form').on('submit', (event) => {
    event.preventDefault();
    var $form = $('#open-form');
    var $button = $form.find('button');

    $.ajax({
      url: '/open',
      type: 'POST',
      data: JSON.stringify($form.serialize()),
      contentType: 'application/json;charset=UTF-8',
      timeout: 10000,
      beforeSend: (xhr, settings) => {
        $button.attr('disabled', true);
      },
      complete: (xhr, textStatus) => {
        $button.attr('disabled', false);
      }
    });

    $('#open-form').hide();
    $('#close-form').show();
    $('#exec-form').show();

    let now = new Date();
    $('#log-area').val($('#log-area').val() + '\n' + '[' + now + '] ' + 'Serial Port Opened...');
    $("#log-area").scrollTop( $("#log-area")[0].scrollHeight);
  });

  $('#close-form').on('submit', (event) => {
    event.preventDefault();
    var $form = $(this);
    var $button = $form.find('button');

    $.ajax({
      url: '/close',
      type: 'POST',
      data: JSON.stringify({"is_connected":"False"}),
      timeout: 10000,
      beforeSend: (xhr, settings) => {
        $button.attr('disabled', true);
      },
      complete: (xhr, textStatus) => {
        $button.attr('disabled', false);
      }
    });

    $('#open-form').show();
    $('#close-form').hide();
    $('#exec-form').hide();

    let now = new Date();
    $('#log-area').val($('#log-area').val() + '\n' + '[' + now + '] ' + 'Serial Port Closed...');
    $("#log-area").scrollTop( $("#log-area")[0].scrollHeight);
  });

  $('#exec-form').on('submit', (event) => {
    event.preventDefault();
    var $form = $('#exec-form');
    var $button = $form.find('button');

    $.ajax({
      url: '/execute',
      type: 'POST',
      contentType: 'application/json;charset=UTF-8',
      data: JSON.stringify($form.serialize()),
      timeout: 10000,
      beforeSend: (xhr, settings) => {
        $button.attr('disabled', true);
      },
      complete: (xhr, textStatus) => {
        $button.attr('disabled', false);
      }
    });

    let now = new Date();
    $('#log-area').val($('#log-area').val() + '\n' + '[' + now + '] ' + $('#device').val());
    $("#log-area").scrollTop( $("#log-area")[0].scrollHeight);
  });

  $('#clear-button').on('click', (event) => {
    $('#log-area').val('');
  });
});
